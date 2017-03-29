#!/usr/bin/env python
# -*- coding: utf-8 -*-

from theano.tensor.signal import pool
from theano.tensor.nnet import conv2d
import theano.tensor as T
import numpy as np
import theano

class LeNetConvPoolLayer(object):

    def __init__(self, rng, input, filter_shape, image_shape, poolsize=(2,2), name='Model', params=None):
        if params != None:
            self.W = theano.shared(params[str(name) + "_W_in"], name=str(name) + "_W_in", borrow=True)
            self.b = theano.shared(params[str(name) + "_b_in"], name=str(name) + "_b_in", borrow=True)
        else:
            assert image_shape[1] == filter_shape[1]
            self.input = input

            fan_in = np.prod(filter_shape[1:])
            fan_out = (filter_shape[0] * np.prod(filter_shape[2:]) // np.prod(poolsize))
            W_bound = np.sqrt(6. / (fan_in + fan_out))
            self.W = theano.shared(
                np.asarray(
                    rng.uniform(low=-W_bound, high=W_bound, size=filter_shape),
                    dtype=np.float32
                ),
                name=str(name) + '_W_in',
                borrow=True
            )

            b_values = np.zeros((filter_shape[0],), dtype=theano.config.floatX)
            self.b = theano.shared(
                value=b_values,
                name=str(name) + '_b_in',
                borrow=True)

        conv_out = conv2d(
            input=input,
            filters=self.W,
            filter_shape=filter_shape,
            input_shape=image_shape
        )

        pooled_out = pool.pool_2d(
            input=conv_out,
            ws=poolsize,
            ignore_border=True
        )

        self.output = T.tanh(pooled_out + self.b.dimshuffle('x', 0, 'x', 'x'))

        self.params = []
        self.params.extend([self.W, self.b])

    def get_params(self):
        params = {}
        for param in self.params:
            params[param.name] = param.get_value()
        return params
