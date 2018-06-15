#!/usr/bin/env python
# -*- coding: utf-8 -*-


import tensorflow as tf
import numpy as np
from tensorflow.examples.tutorials.mnist import input_data

import matplotlib
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
matplotlib.use('Agg')


def vis(images, save_name):
    pass

def model(x, mask, w, b, w_prime, b_prime):
    tilde_x = mask * x

    y = tf.nn.sigmoid(tf.matmul(tilde_x, w) + b)
    z = tf.nn.sigmoid(tf.matmul(y, w_prime) + b_prime)
    return z

mnist_width = 28
n_visible = mnist_width * mnist_width
n_hidden = 500
corruption_level = 0.3

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)
train_x = mnist.train.images
train_y = mnist.train.labels
test_x = mnist.test.images
test_y = mnist.test.labels


x = tf.placeholder(tf.float32, [None, n_visible], name="x")

mask = tf.placeholder(tf.float32, [None, n_visible], name='mask')

w_init_max = 4 * np.sqrt(6. / (n_visible + n_hidden))
w_init = tf.random_uniform(
    shape=[n_visible, n_hidden],
    minval=-w_init_max,
    maxval=w_init_max
)

w = tf.Variable(w_init, name='w')
b = tf.Variable(tf.zeros([n_hidden]), name='b')

w_prime = tf.transpose(w)
b_prime = tf.Variable(tf.zeros([n_visible]), name='b_prime')

z = model(x, mask, w, b, w_prime, b_prime)

cost = tf.reduce_sum(tf.pow(x-z, 2))
train_op = tf.train.GradientDescentOptimizer(0.02).minimize(cost)

predict_op = z

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for i in range(100):
        start_bound = range(0, len(test_x), 128)
        end_bound = range(128, len(test_x)+1, 128)
        for start, end in zip(start_bound, end_bound):
            input_x = test_x[start:end]
            mask_np = np.random.binomial(1, 1-corruption_level, input_x.shape)
            sess.run(
                train_op,
                feed_dict={
                    x: input_x,
                    mask: mask_np
                }
            )
        mask_np = np.random.binomial(1, 1-corruption_level, test_x.shape)
        print("for step: {}".format(i), sess.run(cost, feed_dict={x: test_x, mask: mask_np}))
    mask_np = np.random.binomial(1, 1-corruption_level, test_x[:100].shape)
    predicted_imgs = sess.run(predict_op, feed_dict={x:test_x[:100], mask: mask_np})
    input_imgs = test_x[:100]

    print('Done')
