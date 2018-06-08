#!/usr/bin/env python
# -*- coding: utf-8 -*-


from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from tensorflow.examples.tutorials.mnist import input_data

import argparse
import sys
import tensorflow as tf

max_step = 1000
learning_rate = 0.001
KEEP_PROB = 0.9
input_dim = 784
output_dim = 10

data_dir = '/tmp/mnist/data'
log_dir = '/tmp/mnist/log'

mnist = input_data.read_data_sets(data_dir, one_hot=True)

sess = tf.InteractiveSession()


def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

def bias_variable(shape):
    initial = tf.constant(0.1, shape=shape)
    return tf.Variable(initial)

def variable_summaries(var):
    with tf.name_scope('summaries'):
        mean = tf.reduce_mean(var)
        tf.summary.scalar('mean', mean)

        with tf.name_scope('stddev'):
            stddev = tf.sqrt(tf.reduce_mean(tf.square(var - mean)))
        tf.summary.scalar('stddev', stddev)
        tf.summary.scalar('max', tf.reduce_max(var))
        tf.summary.scalar('min', tf.reduce_min(var))

        tf.summary.histogram('histogram', var)

def nn_layer(input_tensor, input_dim, output_dim, layer_name,
        activation_fun=tf.nn.relu):

    with tf.name_scope('weights'):
        weights = weight_variable([input_dim, output_dim])
        variable_summaries(weights)
    with tf.name_scope('biases'):
        biases = bias_variable([output_dim])
        variable_summaries(biases)
    with tf.name_scope('linear_compute'):
        preactivate = tf.matmul(input_tensor, weights) + biases
        tf.summary.histogram('linear', preactivate)
    activations = activation_fun(preactivate, name='activation')
    tf.summary.histogram('activations', activations)

    return activations

def feed_dict(train):
    if train:
        xs, ys = mnist.train.next_batch(100)
        k = KEEP_PROB
    else:
        xs, ys = mnist.test.images, mnist.test.labels
        k = 1.0
    return {input_x: xs, input_y: ys, keep_prob: k}


with tf.name_scope('input'):
    input_x = tf.placeholder(tf.float32, [None, input_dim], name='x-input')
    input_y = tf.placeholder(tf.float32, [None, output_dim], name='y-input')

with tf.name_scope('input_reshape'):
    image_shaped_input = tf.reshape(input_x, [-1, 28, 28, 1])
    tf.summary.image('input_image', image_shaped_input, 10)

hidden1 = nn_layer(input_x, input_dim, 500, 'hidden1')

with tf.name_scope('dropout'):
    keep_prob = tf.placeholder(tf.float32)
    tf.summary.scalar('dropout_keep_probability', keep_prob)
    dropped = tf.nn.dropout(hidden1, keep_prob)

predict_y = nn_layer(dropped, 500, 10, 'layer2', activation_fun=tf.identity)

with tf.name_scope('loss'):
    diff = tf.nn.softmax_cross_entropy_with_logits(
        labels=input_y, logits=predict_y)
    with tf.name_scope('total'):
        cross_entropy = tf.reduce_mean(diff)

tf.summary.scalar('loss', cross_entropy)

with tf.name_scope('train'):
    train_op = tf.train.AdamOptimizer(learning_rate).minimize(cross_entropy)

with tf.name_scope('accuracy'):
    with tf.name_scope('correct_prediction'):
        correct_prediction = tf.equal(
            tf.argmax(predict_y, 1),
            tf.argmax(input_y, 1)
        )
    with tf.name_scope('accuracy'):
        accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
tf.summary.scalar('accuracy', accuracy)

merged = tf.summary.merge_all()

train_writer = tf.summary.FileWriter(log_dir + '/train', sess.graph)
test_writer = tf.summary.FileWriter(log_dir + '/test')

tf.global_variables_initializer().run()

for i in range(max_step):
    if i % 10 == 0:
        summary, acc = sess.run(
            [merged, accuracy], feed_dict=feed_dict(False))
        test_writer.add_summary(summary, i)
        print('Accuracy at step {}: {}'.format(i, acc))
    else:
        if i % 100 == 99:
            run_options = tf.RunOptions(trace_level=tf.RunOptions.FULL_TRACE)
            run_metadata = tf.RunMetadata()
            summary, _ = sess.run(
                [merged, train_op],
                feed_dict=feed_dict(True),
                options=run_options,
                run_metadata=run_metadata
            )
            train_writer.add_run_metadata(
                run_metadata, 
                'step {}'.format(i)
            )
            train_writer.add_summary(summary, i)
            print('Adding run metadata for: {}'.format(i))
        else:
            summary, _ = sess.run(
                [merged, train_op],
                feed_dict=feed_dict(True)
            )
            train_writer.add_summary(summary, i)
train_writer.close()
test_writer.close()
