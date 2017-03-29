#! /usr/bin/env python

import tensorflow as tf
import numpy as np
import os
import time
import datetime
from text_cnn import TextCNN
from tensorflow.contrib import learn
import csv
import traceback
import sys, pdb

def predict(x_raw, vocab_path, batch_size=64, allow_soft_placement=True, log_device_placement=False):
    checkpoint_dir = "./runs/2class/checkpoints";
    vocab_processor = learn.preprocessing.VocabularyProcessor.restore(vocab_path)

# Map data into vocabulary
    x_test = np.array(list(vocab_processor.transform(x_raw)))

    print("\nEvaluating...\n")

# Evaluation
# ==================================================
    try:
        checkpoint_file = tf.train.latest_checkpoint(checkpoint_dir)
        print(checkpoint_file, "{}.meta".format(checkpoint_file))
        graph = tf.Graph()
        with graph.as_default():
            session_conf = tf.ConfigProto(
              allow_soft_placement=allow_soft_placement,
              log_device_placement=log_device_placement)
            sess = tf.Session(config=session_conf)
            with sess.as_default():
                # Load the saved meta graph and restore variables
                saver = tf.train.import_meta_graph("{}.meta".format(checkpoint_file))
                saver.restore(sess, checkpoint_file)

                # Get the placeholders from the graph by name
                input_x = graph.get_operation_by_name("input_x").outputs[0]
                # input_y = graph.get_operation_by_name("input_y").outputs[0]
                dropout_keep_prob = graph.get_operation_by_name("dropout_keep_prob").outputs[0]

                # Tensors we want to evaluate
                predictions = graph.get_operation_by_name("output/predictions").outputs[0]

                # Generate batches for one epoch
                batches = batch_iter(list(x_test), batch_size, 1, shuffle=False)

                # Collect the predictions here
                all_predictions = []

                for x_test_batch in batches:
                    batch_predictions = sess.run(predictions, {input_x: x_test_batch, dropout_keep_prob: 1.0})
                    all_predictions = np.concatenate([all_predictions, batch_predictions])

        return all_predictions
    except:
        traceback.print_exc(file=sys.stdout)

def batch_iter(data, batch_size, num_epochs, shuffle=True):
    """
    Generates a batch iterator for a dataset.
    """
    data = np.array(data)
    data_size = len(data)
    num_batches_per_epoch = int((len(data)-1)/batch_size) + 1
    for epoch in range(num_epochs):
        # Shuffle the data at each epoch
        if shuffle:
            shuffle_indices = np.random.permutation(np.arange(data_size))
            shuffled_data = data[shuffle_indices]
        else:
            shuffled_data = data
        for batch_num in range(num_batches_per_epoch):
            start_index = batch_num * batch_size
            end_index = min((batch_num + 1) * batch_size, data_size)
            yield shuffled_data[start_index:end_index]

if __name__=='__main__':
    x_raw = []
    with open('predict.in', 'rb') as f:
        for line in f:
            x_raw.append(line.strip().decode('utf-8'))
    predictres = predict(x_raw, vocab_path='vocab')
    print(predictres)
