#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np

def model(x, w):
    return tf.multiply(x, w)

x_train = np.linspace(-1, 1, 101)
y_train = 2 * x_train + np.random.randn(*x_train.shape) * 0.33

x = tf.placeholder("float")
y = tf.placeholder("float")

w = tf.Variable(0.0, name="weights")
y_model = model(x, w)

cost = tf.square(y-y_model)
train_op = tf.train.GradientDescentOptimizer(0.01).minimize(cost)

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for i in range(100):
        for (tx, ty) in zip(x_train, y_train):
            sess.run(train_op, feed_dict={x:tx, y:ty})
    print(sess.run(w))
