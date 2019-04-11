#!/usr/bin/env python
# -*- coding: utf-8 -*-

import collections
import numpy as np
import tensorflow as tf
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


batch_size = 20
embedding_size = 2
num_sampled = 15


sentences = ["the quick brown fox jumped over the lazy dog",
            "I love cats and dogs",
            "we all love cats and dogs",
            "cats and dogs are great",
            "sung likes cats",
            "she loves dogs",
            "cats can be very independent",
            "cats are great companions when they want to be",
            "cats are playful",
            "cats are natural hunters",
            "It's raining cats and dogs",
            "dogs and cats love sung"]

words = " ".join(sentences).split()
count = collections.Counter(words).most_common()

print("Word count: ", count[:10]) 

rdic = [x[0] for x in count]
dic = { w: i for i, w in enumerate(rdic) }
voc_size = len(dic)

data = [dic[word] for word in words]
print("Sample data: {} {}".format(data[:10], [rdic[t] for t in data[:10]]))


cbow_pairs = []
for i in range(1, len(data) - 1):
    cbow_pairs.append([[data[i-1], data[i+1]], data[i]])
print("CBOW pairs sample: {}".format(cbow_pairs[:10]))

skip_gram_pairs = []
for c in cbow_pairs:
    skip_gram_pairs.append([c[1], c[0][0]])
    skip_gram_pairs.append([c[1], c[0][1]])
print("Skip gram pairs: {}".format(skip_gram_pairs[:10]))


def generate_batch(size):
    assert size < len(skip_gram_pairs)
    x_data = []
    y_data = []
    r = np.random.choice(range(len(skip_gram_pairs)), size, replace=False)
    for i in r:
        x_data.append(skip_gram_pairs[i][0])
        y_data.append([skip_gram_pairs[i][1]])
    return x_data, y_data

print('Batches (x, y)', generate_batch(3))


train_inputs = tf.placeholder(tf.int32, shape=[batch_size])
train_labels = tf.placeholder(tf.int32, shape=[batch_size, 1])

with tf.device('/cpu:0'):
    embeddings = tf.Variable(
        tf.random_uniform([voc_size, embedding_size], -1.0, 1.0)
    )
    embed = tf.nn.embedding_lookup(embeddings, train_inputs)

nce_weights = tf.Variable(
    tf.random_uniform([voc_size, embedding_size], -1.0, 1.0)
)
nce_biases = tf.Variable(tf.zeros([voc_size]))

loss = tf.reduce_mean(
    tf.nn.nce_loss(
        nce_weights, nce_biases, train_labels, embed, num_sampled, voc_size))

train_op = tf.train.AdamOptimizer(1e-1).minimize(loss)

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for step in range(100):
        batch_inputs, batch_labels = generate_batch(batch_size)
        _, loss_val = sess.run([train_op, loss],
                feed_dict={train_inputs: batch_inputs, train_labels: batch_labels})
        if step % 10 == 0:
          print("Loss at ", step, loss_val) # Report the loss

    trained_embeddings = embeddings.eval()
