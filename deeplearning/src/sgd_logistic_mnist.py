#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import gzip
import theano
import pickle
import numpy as np
import theano.tensor as T
import timeit
from sgd_logistic import LogisticRegression as LR

def load_data(datafile):
    with gzip.open(datafile) as f:
        try:
            train_set, valid_set, test_set = pickle.load(f, encoding='latin1')
        except:
            train_set, valid_set, test_set = pickle.load(f)

    def shared_dataset(data_xy, borrow=True):
        data_x, data_y = data_xy

        #print data_x.ndim, data_y.ndim, data_y, len(data_x), len(data_y)

        shared_x = theano.shared(np.asarray(data_x, dtype=theano.config.floatX),
                borrow=borrow)

        shared_y = theano.shared(np.asarray(data_y, dtype=theano.config.floatX),
                borrow=borrow)
        return shared_x, T.cast(shared_y, 'int32')

    train_set_x, train_set_y = shared_dataset(train_set)
    valid_set_x, valid_set_y = shared_dataset(valid_set)
    test_set_x, test_set_y = shared_dataset(test_set)

    rval = [(train_set_x, train_set_y), (valid_set_x, valid_set_y),
                                        (test_set_x, test_set_y)]
    return rval

def sgd_optimization_mnist(learning_rate=0.13, n_epochs=1000, dataset='mnist.pkl.gz', batch_size=600):
    datasets = load_data(dataset)

    train_set_x, train_set_y = datasets[0]
    valid_set_x, valid_set_y = datasets[1]
    test_set_x, test_set_y = datasets[2]

    n_train_batches = train_set_x.get_value(borrow=True).shape[0] // batch_size
    n_valid_batches = valid_set_x.get_value(borrow=True).shape[0] // batch_size
    n_test_batches = test_set_x.get_value(borrow=True).shape[0] // batch_size

    print('... building the model')

    index = T.lscalar()

    x = T.matrix('x')
    y = T.ivector('y')

    classifier = LR(input=x, n_in = 28*28, n_out = 10)
    cost = classifier.negative_log_likelihood(y)

    test_model = theano.function(
        inputs=[index],
        outputs=classifier.errors(y),
        givens={
            x: test_set_x[index * batch_size: (index+1) * batch_size],
            y: test_set_y[index * batch_size: (index+1) * batch_size]
        }
    )

    validate_model = theano.function(
        inputs=[index],
        outputs=classifier.errors(y),
        givens={
            x: valid_set_x[index * batch_size: (index+1) * batch_size],
            y: valid_set_y[index * batch_size: (index+1) * batch_size]
        }
    )

    g_W = T.grad(cost=cost, wrt=classifier.W)
    g_b = T.grad(cost=cost, wrt=classifier.b)

    updates = [(classifier.W, classifier.W - learning_rate * g_W), 
               (classifier.b, classifier.b - learning_rate * g_b)]

    train_model = theano.function(
        inputs=[index],
        outputs = cost,
        updates = updates,
        givens = {
            x: train_set_x[index * batch_size: (index+1) * batch_size],
            y: train_set_y[index * batch_size: (index+1) * batch_size]
        }
    )

    print 'training...'
    patience = 5000
    patience_increase = 2

    improvement_threshold=0.995
    validation_frequency = min(n_train_batches, patience // 2)

    best_validation_loss = np.inf
    test_score = 0.
    start_time = timeit.default_timer()

    done_looping = 0
    epoch = 0

    while(epoch < n_epochs) and (not done_looping):
        epoch = epoch + 1
        for minibatch_index in range(n_train_batches):
            minibatch_avg_cost = train_model(minibatch_index)

            iter = (epoch - 1) * n_train_batches + minibatch_index

            if (iter + 1) % validation_frequency == 0:
                validation_losses = [validate_model(i) for i in range(n_valid_batches)]
                this_validation_loss = np.mean(validation_losses)

                print (
                    'epoch %i, minibatch %i/%i, validation error %f %%' %
                    (
                        epoch,
                        minibatch_index + 1,
                        n_train_batches,
                        this_validation_loss * 100.
                    )
                )

                if this_validation_loss < best_validation_loss:
                    if this_validation_loss < best_validation_loss * \
                        improvement_threshold:
                        patience = max(patience, iter * patience_increase)
                    best_validation_loss = this_validation_loss
                    test_losses = [test_model(i) for i in range(n_test_batches)]
                    test_score = np.mean(test_losses)

                    print (
                        ('      epoch %i, minibatch %i/%i, test error of best model %f %%') %
                        (
                            epoch,
                            minibatch_index + 1,
                            n_train_batches,
                            test_score * 100.
                        )
                    )

                    with open('sgd_mnist_best_model.pkl', 'wb') as f:
                        pickle.dump(classifier, f)


            if patience <= iter:
                done_looping = True
                break

    end_time = timeit.default_timer()
    print(
        (
            'Optimization complete with best validation score of %f %%,'
            'with test performance %f %%'
        )
        % (best_validation_loss * 100., test_score * 100.)
    )
    print('The code run for %d epochs, with %f epochs/sec' % (
        epoch, 1. * epoch / (end_time - start_time)))

def predict(dataset='mnist.pkl.gz'):
    classifier = pickle.load(open('sgd_mnist_best_model.pkl'))

    predict_model = theano.function(inputs=[classifier.input], outputs=classifier.y_pred)

    datasets = load_data(dataset)
    test_set_x, test_set_y = datasets[2]
    test_set_x = test_set_x.get_value()

    predicted_values = predict_model(test_set_x[:10])
    print("Predicted values for the first 10 examples of test set:")
    print(predicted_values)


if __name__=='__main__':
    #sgd_optimization_mnist(dataset="../data/DeepLearningTutorials/data/mnist.pkl.gz")
    predict(dataset="../data/DeepLearningTutorials/data/mnist.pkl.gz")
