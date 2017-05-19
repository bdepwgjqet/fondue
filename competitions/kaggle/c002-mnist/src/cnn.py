#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np
import pandas as pd

def init_weights(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01))


def cnn(x, w, w2, w3, w4, w_o, p_keep_conv, p_keep_hidden):
    l1a = tf.nn.relu(tf.nn.conv2d(x, w, strides=[1,1,1,1], padding='SAME'))
    l1 = tf.nn.max_pool(l1a, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME')
    # 14*14
    l1 = tf.nn.dropout(l1, p_keep_conv)

    l2a = tf.nn.relu(tf.nn.conv2d(l1, w2, strides=[1,1,1,1], padding='SAME'))
    l2 = tf.nn.max_pool(l2a, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME')
    # 7*7
    l2 = tf.nn.dropout(l2, p_keep_conv)

    l3a = tf.nn.relu(tf.nn.conv2d(l2, w3, strides=[1,1,1,1], padding='SAME'))
    l3 = tf.nn.max_pool(l3a, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME')
    # 4*4
    l3 = tf.reshape(l3, [-1, w4.get_shape().as_list()[0]])
    l3 = tf.nn.dropout(l3, p_keep_conv)

    l4 = tf.nn.relu(tf.matmul(l3, w4))
    l4 = tf.nn.dropout(l4, p_keep_hidden)

    pyx = tf.matmul(l4, w_o)
    return pyx


batch_size=128

train_df = pd.read_csv("../data/train.csv")
predict_df= pd.read_csv("../data/test.csv")

y_label = train_df["label"].as_matrix()
x_base = train_df.drop(["label"], axis=1).as_matrix()
x_base = np.array(x_base, dtype=float)
x_predict = predict_df.as_matrix()

x_base = np.multiply(x_base, 1.0/255.0)

y_base = []
for i in range(len(y_label)):
    yc = np.zeros([10])
    yc[y_label[i]] = 1.
    y_base.append(yc)
y_base=np.asarray(y_base)

x_train = x_base[2000:]
y_train = y_base[2000:]
x_test = x_base[:2000]
y_test = y_base[:2000]

x_train = x_train.reshape(-1, 28, 28, 1)
x_test = x_test.reshape(-1, 28, 28, 1)
x_predict = x_predict.reshape(-1, 28, 28, 1)

x = tf.placeholder(tf.float32, shape=[None, 28, 28, 1])
y = tf.placeholder(tf.float32, shape=[None, 10])

w = init_weights([3, 3, 1, 32])
w2 = init_weights([3, 3, 32, 64])
w3 = init_weights([3, 3, 64, 128])
w4 = init_weights([128*4*4, 625])
w_o = init_weights([625, 10])

p_keep_conv = tf.placeholder("float")
p_keep_hidden = tf.placeholder("float")
py_x = cnn(x, w, w2, w3, w4, w_o, p_keep_conv, p_keep_hidden)


cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=py_x, labels=y))
train_op = tf.train.RMSPropOptimizer(0.001, 0.9).minimize(cost)
predict_op = tf.argmax(py_x, axis=1)

mxacc = 0
test_size = 500
with tf.Session() as sess:
    tf.global_variables_initializer().run()
    for step in range(200):
        for start,end in zip(range(0, len(x_train), batch_size), range(batch_size, len(x_train)+1, batch_size)):
            sess.run(train_op, feed_dict={x: x_train[start:end], y:y_train[start:end], p_keep_conv:0.8, p_keep_hidden:0.5})
        test_indices = np.arange(len(x_test))
        np.random.shuffle(test_indices)

        acc = np.mean(np.argmax(y_test[test_indices], axis=1)==sess.run(predict_op, feed_dict={x: x_test[test_indices], p_keep_conv:1.0, p_keep_hidden:1.0}))
        print("Step {0}, Acc: {1}".format(step, acc))
        if mxacc < acc:
            mxacc = acc
            y_predict = sess.run(predict_op, feed_dict={x:x_predict, p_keep_conv:0.8, p_keep_hidden:0.5})
            y_df = pd.DataFrame({'ImageId': range(1, len(y_predict)+1), 'Label': y_predict.tolist()})
            y_df.to_csv("../data/predict.csv", index=False)
