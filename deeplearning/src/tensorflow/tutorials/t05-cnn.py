#!/usr/bin/env python
# -*- coding: utf-8 -*-


import tensorflow as tf
import numpy as np
from tensorflow.examples.tutorials.mnist import input_data


batch_size = 128
test_size = 256

def init_weights(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01))

def model(x, w1, w2, w3, w4, wo, conv_keep_prob, hidden_keep_prob):
    l1a = tf.nn.relu(
        tf.nn.conv2d(x, w1, strides=[1,1,1,1], padding='SAME')
    )
    l1 = tf.nn.max_pool(
        l1a, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME'
    )
    l1 = tf.nn.dropout(l1, conv_keep_prob)

    l2a = tf.nn.relu(
        tf.nn.conv2d(l1, w2, strides=[1,1,1,1], padding='SAME')
    )
    l2 = tf.nn.max_pool(
        l2a, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME'
    )
    l2 = tf.nn.dropout(l2, conv_keep_prob)

    l3a = tf.nn.relu(
        tf.nn.conv2d(l2, w3, strides=[1,1,1,1], padding='SAME')
    )
    l3 = tf.nn.max_pool(
        l3a, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME'
    )
    l3 = tf.reshape(l3, [-1, w4.get_shape().as_list()[0]])
    l3 = tf.nn.dropout(l3, conv_keep_prob)

    l4 = tf.nn.relu(tf.matmul(l3, w4))
    l4 = tf.nn.dropout(l4, hidden_keep_prob)

    py = tf.matmul(l4, wo)
    return py




mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

train_x = mnist.train.images
train_y = mnist.train.labels
test_x = mnist.test.images
test_y = mnist.test.labels

train_x = train_x.reshape(-1, 28, 28, 1)
test_x = test_x.reshape(-1, 28, 28, 1)

x = tf.placeholder(tf.float32, [None, 28, 28, 1])
y = tf.placeholder(tf.float32, [None, 10])

w1 = init_weights([3, 3, 1, 32])
w2 = init_weights([3, 3, 32, 64])
w3 = init_weights([3, 3, 64, 128])
w4 = init_weights([128*4*4, 625])
wo = init_weights([625, 10])

conv_keep_prob = tf.placeholder(tf.float32)
hidden_keep_prob = tf.placeholder(tf.float32)

py = model(x, w1, w2, w3, w4, wo, conv_keep_prob, hidden_keep_prob)
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=py,
    labels=y
))
train_op = tf.train.RMSPropOptimizer(0.001, 0.9).minimize(cost)
predict_op = tf.argmax(py, 1)


with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for step in range(100):
        start_bound = range(0, len(test_x), batch_size)
        end_bound = range(batch_size, len(test_x)+1, batch_size)
        for start, end in zip(start_bound, end_bound):
            sess.run(
                train_op, 
                feed_dict={
                    x: test_x[start:end],
                    y: test_y[start:end],
                    conv_keep_prob: 0.8,
                    hidden_keep_prob: 0.5
                }
            )

        test_indices = np.arange(len(test_x))
        np.random.shuffle(test_indices)
        test_indices = test_indices[0:test_size]

        print(
            "For step: {}".format(step),
            np.mean(
                np.argmax(test_y[test_indices], axis=1) == sess.run(
                    predict_op,
                    feed_dict={
                        x: test_x[test_indices],
                        conv_keep_prob: 0.8,
                        hidden_keep_prob: 0.5
                    }
                )
            )
        )



