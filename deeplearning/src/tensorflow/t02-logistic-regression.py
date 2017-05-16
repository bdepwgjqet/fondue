#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np
from tensorflow.examples.tutorials.mnist import input_data

def init_weights(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01))

batch_size=128

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)
x_train, y_train, x_test, y_test = mnist.train.images, mnist.train.labels, mnist.test.images, mnist.test.labels

x = tf.placeholder(tf.float32, shape=[None, 784])
y = tf.placeholder(tf.float32, shape=[None, 10])

w = init_weights([784, 10])
py_x = tf.matmul(x, w)

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=py_x, labels=y))
train_op = tf.train.GradientDescentOptimizer(0.05).minimize(cost)
predict_op = tf.argmax(py_x, axis=1)

with tf.Session() as sess:
    tf.global_variables_initializer().run()
    for step in range(100):
        for start,end in zip(range(0, len(x_train), batch_size), range(batch_size, len(x_train)+1, batch_size)):
            sess.run(train_op, feed_dict={x: x_train[start:end], y:y_train[start:end]})
        print("Step {0}, Acc: {1}".format(step, np.mean(np.argmax(y_test, axis=1)==sess.run(predict_op, feed_dict={x: x_test}))))

