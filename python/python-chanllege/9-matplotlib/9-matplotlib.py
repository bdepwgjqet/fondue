#!/usr/bin/python

from pylab import *

if __name__=='__main__':

    first_f = open("first.in")
    first = first_f.read()
    first_a = [int(x.strip()) for x in first.split(',')]
    second_f = open("second.in")
    second = second_f.read()
    second_a = [int(x.strip()) for x in second.split(',')]

    x = [first_a[e] for e in range(0,len(first_a),2)]
    y = [first_a[e] for e in range(1,len(first_a),2)]

    plot(x,y)

    x = [second_a[e] for e in range(0,len(second_a),2)]
    y = [second_a[e] for e in range(1,len(second_a),2)]

    plot(x,y)
    show()
