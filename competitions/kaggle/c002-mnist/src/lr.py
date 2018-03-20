#!/usr/bin/env python
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np
import pandas as pd

def init_weights(shape):
    return tf.Variable(tf.random_normal(shape, stddev=0.01))

batch_size=128

train_df = pd.read_csv("../data/train.csv")
predict_df= pd.read_csv("../data/test.csv")

y_label = train_df["label"].as_matrix()
x_base = train_df.drop(["label"], axis=1).as_matrix()
x_base = np.array(x_base, dtype=float)
x_predict = predict_df.as_matrix()

for i in range(len(x_base)):
    for j in range(len(x_base[i])):
        x_base[i][j] = 1.0 * x_base[i][j] / 255.0

y_base = []
for i in range(len(y_label)):
    yc = []
    for j in range(10):
        yc.append(0.)
    yc[y_label[i]] = 1.
    y_base.append(yc)
y_base=np.asanyarray(y_base)

x_train = x_base[1000:]
y_train = y_base[1000:]
x_test = x_base[:1000]
y_test = y_base[:1000]

print(x_train.shape, y_train.shape)
print(x_base[0], y_base[0])

x = tf.placeholder(tf.float32, shape=[None, 784])
y = tf.placeholder(tf.float32, shape=[None, 10])

w = init_weights([784, 10])
py_x = tf.matmul(x, w)

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=py_x, labels=y))
train_op = tf.train.GradientDescentOptimizer(0.05).minimize(cost)
predict_op = tf.argmax(py_x, axis=1)

mxacc = 0
with tf.Session() as sess:
    tf.global_variables_initializer().run()
    for step in range(100):
        for start,end in zip(range(0, len(x_train), batch_size), range(batch_size, len(x_train)+1, batch_size)):
            sess.run(train_op, feed_dict={x: x_train[start:end], y:y_train[start:end]})
        acc = np.mean(np.argmax(y_test, axis=1)==sess.run(predict_op, feed_dict={x: x_test}))
        print("Step {0}, Acc: {1}".format(step, acc))
        if mxacc < acc:
            mxacc = acc
            y_predict = sess.run(predict_op, feed_dict={x:x_predict})
            y_df = pd.DataFrame({'ImageId': range(1, len(y_predict)+1), 'Label': y_predict.tolist()})
            print(y_df.head())
            y_df.to_csv("../data/predict.csv", index=False)
