#!/usr/bin/env python
# -*- coding: utf-8 -*-


import numpy as np
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

steps = 200

def init_weight(shape):
    return tf.Variable(tf.random_normal(shape=shape, stddev=0.01))

# mlp
def model(x, w_h, w_o):
    x_h = tf.nn.sigmoid(tf.matmul(x, w_h))
    return tf.matmul(x_h, w_o)



mnist = input_data.read_data_sets(
    "MNIST_data/", one_hot=True)
train_x = mnist.train.images
train_y = mnist.train.labels
test_x = mnist.test.images
test_y = mnist.test.labels


x = tf.placeholder(tf.float32, [None, 784])
y = tf.placeholder(tf.float32, [None, 10])

w_h = init_weight([784, 625])
w_o = init_weight([625, 10])

py = model(x, w_h, w_o)
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=py,
    labels=y
))
train_op = tf.train.GradientDescentOptimizer(0.05).minimize(cost)
predict_op = tf.argmax(py, 1)

with tf.Session() as sess:
    tf.global_variables_initializer().run()
    
    for step in range(steps):
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
            "For step: {}".format(step), 
            np.mean(np.argmax(test_y, axis=1)==sess.run(
                predict_op, 
                feed_dict={
                    x: test_x
                }
            ))
        )
