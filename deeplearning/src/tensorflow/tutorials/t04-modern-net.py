#!/usr/bin/env python
# -*- coding: utf-8 -*-


import tensorflow as tf
import numpy as np

from tensorflow.examples.tutorials.mnist import input_data

def init_weight(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01))

# mlp with extra hidden layer + dropout
def model(x, w_h, w_h2, w_o, input_keep_prob, hidden_keep_prob):
    x = tf.nn.dropout(x, input_keep_prob)

    h_x = tf.nn.relu(tf.matmul(x, w_h))
    h_x = tf.nn.dropout(h_x, hidden_keep_prob)

    h2_x = tf.nn.relu(tf.matmul(h_x, w_h2))
    h2_x = tf.nn.dropout(h2_x, hidden_keep_prob)

    return tf.matmul(h2_x, w_o)



mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

x_train = mnist.train.images
y_train = mnist.train.labels
x_test = mnist.test.images
y_test = mnist.test.labels


x = tf.placeholder(tf.float32, [None, 784])
y = tf.placeholder(tf.float32, [None, 10])

w_h = init_weight([784, 625])
w_h2 = init_weight([625, 625])
w_o = init_weight([625, 10])


input_keep_prob = tf.placeholder(tf.float32)
hidden_keep_prob = tf.placeholder(tf.float32)

py = model(x, w_h, w_h2, w_o, input_keep_prob, hidden_keep_prob)
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(
    logits=py,
    labels=y
))
train_op = tf.train.RMSPropOptimizer(0.001, 0.9).minimize(cost)
predict_op = tf.argmax(py, 1)

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for step in range(100):
        start_bound = range(0, len(x_train), 128)
        end_bound = range(128, len(x_train)+1, 128)
        for start, end in zip(start_bound, end_bound):
            sess.run(
                train_op,
                feed_dict={ 
                    x: x_train[start:end],
                    y: y_train[start:end],
                    input_keep_prob: 0.8,
                    hidden_keep_prob: 0.5
                }
            )
        print(
            "For step {}:".format(step),
            np.mean(np.argmax(y_test, axis=1)==sess.run(
                predict_op, feed_dict={ 
                    x: x_test,
                    input_keep_prob: 1.0,
                    hidden_keep_prob: 1.0
                }
            ))
        )
