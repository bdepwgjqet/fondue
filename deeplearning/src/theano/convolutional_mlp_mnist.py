#!/usr/bin/env python
# -*- coding: utf-8 -*-

from sgd_logistic_mnist import load_data
from lenet_conv_pool_layer import LeNetConvPoolLayer
from sgd_logistic import LogisticRegression
from mlp import HiddenLayer
from mlp import MLP
import theano.tensor as T
import numpy as np
import theano
import pickle
import timeit

def lenet5_mnist_train(learning_rate=0.1, n_epochs=200, dataset='mnist.pkl.gz', nkerns=[20, 50], batch_size=500):

    rng = np.random.RandomState(23455)
    datasets = load_data(dataset)

    train_set_x, train_set_y = datasets[0]
    valid_set_x, valid_set_y = datasets[1]
    test_set_x, test_set_y = datasets[2]

    n_train_batches = train_set_x.get_value(borrow=True).shape[0] // batch_size
    n_valid_batches = valid_set_x.get_value(borrow=True).shape[0] // batch_size
    n_test_batches = test_set_x.get_value(borrow=True).shape[0] // batch_size

    index = T.lscalar()  # index to a [mini]batch

    x = T.matrix('x')  # the data is presented as rasterized images
    y = T.ivector('y')  # the labels are presented as 1D vector of

    print('... building the model')

    layer0_input = x.reshape((batch_size, 1, 28, 28))

    layer0 = LeNetConvPoolLayer(
        rng,
        input=layer0_input,
        image_shape=(batch_size, 1, 28, 28),
        filter_shape=(nkerns[0], 1, 5, 5),
        poolsize=(2, 2)
    )

    layer1 = LeNetConvPoolLayer(
        rng,
        input=layer0.output,
        image_shape=(batch_size, nkerns[0], 12, 12),
        filter_shape=(nkerns[1], nkerns[0], 5, 5),
        poolsize=(2, 2)
    )

    layer2_input = layer1.output.flatten(2)

    layer2 = HiddenLayer(
        rng,
        input = layer2_input,
        n_in = nkerns[1]*4*4,
        n_out = 500,
        activation=T.tanh
    )

    layer3 = LogisticRegression(
        input=layer2.output,
        n_in=500,
        n_out=10
    )

    cost = layer3.negative_log_likelihood(y)

    test_model = theano.function(
        [index],
        layer3.errors(y),
        givens={
            x: test_set_x[index * batch_size:(index + 1) * batch_size],
            y: test_set_y[index * batch_size:(index + 1) * batch_size]
        }
    )

    validate_model = theano.function(
        [index],
        layer3.errors(y),
        givens={
            x: valid_set_x[index * batch_size:(index + 1) * batch_size],
            y: valid_set_y[index * batch_size:(index + 1) * batch_size]
        }
    )

    params = layer3.params + layer2.params + layer1.params + layer0.params
    grads = T.grad(cost, params)

    updates = [
        (param_i, param_i - learning_rate * grad_i) for param_i, grad_i in zip(params, grads)
    ]

    train_model = theano.function(
        [index],
        cost,
        updates=updates,
        givens={
            x: train_set_x[index * batch_size: (index + 1) * batch_size],
            y: train_set_y[index * batch_size: (index + 1) * batch_size]
        }
    )


    print('... training')
    patience = 10000  # look as this many examples regardless
    patience_increase = 2  # wait this much longer when a new best is

    improvement_threshold = 0.995  # a relative improvement of this much is
    validation_frequency = min(n_train_batches, patience // 2)

    best_validation_loss = np.inf
    best_iter = 0
    test_score = 0.
    start_time = timeit.default_timer()

    epoch = 0
    done_looping = False

    while (epoch < n_epochs) and (not done_looping):
        epoch = epoch + 1
        for minibatch_index in range(n_train_batches):

            iter = (epoch - 1) * n_train_batches + minibatch_index
            if iter % 100 == 0:
                print('training @ iter = ', iter)
            cost_ij = train_model(minibatch_index)

            if (iter + 1) % validation_frequency == 0:

                validation_losses = [validate_model(i) for i in range(n_valid_batches)]
                this_validation_loss = np.mean(validation_losses)
                print(
                    'epoch %i, minibatch %i/%i, validation error %f %%' % 
                    ( 
                        epoch, 
                        minibatch_index + 1,
                        n_train_batches,
                        this_validation_loss * 100.
                    )
                ) 

                if this_validation_loss < best_validation_loss:

                    if (this_validation_loss < best_validation_loss * improvement_threshold):
                        patience = max(patience, iter * patience_increase) 

                    best_validation_loss = this_validation_loss
                    best_iter = iter 
                    test_losses = [test_model(i) for i in range(n_test_batches)]
                    test_score = np.mean(test_losses) 
                    print(('     epoch %i, minibatch %i/%i, test error of '
                        'best model %f %%') %
                        (
                            epoch, 
                            minibatch_index + 1, 
                            n_train_batches, test_score * 100.
                        )
                    ) 
                    
            if patience <= iter: 
                done_looping = True
                break 
    end_time = timeit.default_timer()
    print(('Optimization complete. Best validation score of %f %% '
        'obtained at iteration %i, with test performance %f %%') % (best_validation_loss * 100., best_iter + 1, test_score * 100.))

# todo implement save/load params by: https://github.com/Theano/Theano/wiki/Cookbook 
def lenet5_mnist_predict(dataset='mnist.pkl.gz', batch_size=10, nkerns=[20, 50]):
    params = pickle.load(open("lenet5_mnist_best_model.pkl", "rb"), encoding="latin1")

    rng = np.random.RandomState(23455)
    index = T.lscalar()  # index to a [mini]batch
    x = T.matrix('x') 
    layer0_input = x.reshape((batch_size, 1, 28, 28))

    layer0 = LeNetConvPoolLayer(
        rng,
        input=layer0_input,
        image_shape=(batch_size, 1, 28, 28),
        filter_shape=(nkerns[0], 1, 5, 5),
        poolsize=(2, 2)
    )

    layer1 = LeNetConvPoolLayer(
        rng,
        input=layer0.output,
        image_shape=(batch_size, nkerns[0], 12, 12),
        filter_shape=(nkerns[1], nkerns[0], 5, 5),
        poolsize=(2, 2)
    )

    layer2_input = layer1.output.flatten(2)

    layer2 = HiddenLayer(
        rng,
        input = layer2_input,
        n_in = nkerns[1]*4*4,
        n_out = 500,
        activation=T.tanh
    )

    layer3 = LogisticRegression(
        input=layer2.output,
        n_in=500,
        n_out=10
    )

    print(params)

    layer3.W, layer3.b, layer2.W, layer2.b, layer1.W, layer1.b, layer0.W, layer0.b = params
    print(layer3.W, layer3.b)

    datasets = load_data(dataset)
    test_set_x, test_set_y = datasets[2]
    print(type(test_set_x), type(test_set_y))
    test_set_x = test_set_x.get_value()

    predict_model = theano.function(
        inputs=[layer0.input],
        outputs=layer3.y_pred
    )
    predicted_values = predict_model(np.reshape(test_set_x[:batch_size], (batch_size, 1, 28, 28)))
    print("Predict values for the first 10 examples of test set: ")
    print(predicted_values)



    print(len(params))

if __name__=='__main__':
    lenet5_mnist_train(dataset='../data/DeepLearningTutorials/data/mnist.pkl.gz')
    #lenet5_mnist_predict(dataset='../data/DeepLearningTutorials/data/mnist.pkl.gz')
