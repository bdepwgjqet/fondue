#!/usr/bin/env python
# -*- coding: utf-8 -*-


import tensorflow as tf
import numpy as np



def generate_data():
    train_x = np.random.uniform(-10.0, 10.0, size=100)
    train_y = 5*np.square(train_x) + 3
    return train_x, train_y

input_x = tf.placeholder(tf.float32)
input_y = tf.placeholder(tf.float32)

w = tf.get_variable('w', shape=[3, 1])

f = tf.stack([tf.square(input_x), input_x, tf.ones_like(input_x)], 1)
predict_y = tf.squeeze(tf.matmul(f, w), 1)
loss = tf.nn.l2_loss(predict_y - input_y) + 0.1*tf.nn.l2_loss(w)

train_op = tf.train.AdamOptimizer(learning_rate=0.1).minimize(loss)

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    for i in range(1000):
        tx, ty = generate_data()
        sess.run(
            train_op, feed_dict={
                input_x: tx,
                input_y: ty
            }
        )
        if i % 100 == 0:
            print(sess.run(w))
