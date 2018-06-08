#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np

from tensorflow.examples.tutorials.mnist import input_data

steps = 1000


def init_weights(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01))

def model(x, w):
    return tf.matmul(x, w)

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

train_x = mnist.train.images
train_y = mnist.train.labels
test_x = mnist.test.images
test_y = mnist.test.labels

x = tf.placeholder(tf.float32, [None, 784])
y = tf.placeholder(tf.float32, [None, 10])

w = init_weights([784, 10])

p_y = tf.nn.softmax(model(x, w))

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=p_y,
    labels=y
))

train_op = tf.train.GradientDescentOptimizer(0.05).minimize(cost)
predict_op = tf.arg_max(p_y, 1)

with tf.Session() as sess:
    tf.global_variables_initializer().run()
    for i in range(steps):
        start_bound = range(0, len(train_x), 128)
        end_bound = range(128, len(train_x)+1, 128)
        for start, end in zip(start_bound, end_bound):
            sess.run(
                train_op,
                feed_dict={
                    x: train_x[start:end],
                    y: train_y[start:end]
                }
            )
        print(
            "Steps: {}".format(i),
            np.mean(
                np.argmax(test_y, axis=1) == sess.run(
                predict_op, feed_dict={x: test_x})
            )
        )
