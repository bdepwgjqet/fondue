#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np

x_train = np.linspace(-1, 1, 100)
y_train = 2*x_train + np.random.randn(*x_train.shape)*0.13

x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

w = tf.Variable(0.0, name="weight")
y_model = tf.multiply(x, w)

cost = tf.square(y-y_model)
train_op = tf.train.GradientDescentOptimizer(0.01).minimize(cost)

steps = 100

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for i in range(steps): 
        for tx, ty in zip(x_train, y_train):
            sess.run(train_op, feed_dict={x:tx, y:ty})
    print(sess.run(w))
