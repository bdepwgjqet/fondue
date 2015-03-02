#!/usr/bin/python

import pickle

def brute_solve():
    file_name='5.in'
    f = file(file_name)
    ret = pickle.load(f)
    for e in ret:
        s=""
        for u in e:
            s+=u[0]*u[1]
        print s
        
def beauty_solve():
    file_name='5.in'
    f = file(file_name)
    ret = pickle.load(f)
    for e in ret:
        print "".join(map(lambda p:p[0]*p[1],e))

def fun(x):
    return x[0]*x[1]

def middle_solve():
    file_name='5.in'
    f = file(file_name)
    ret = pickle.load(f)
    for e in ret:
        print "".join(map(fun,e))

if __name__=='__main__':    
    #brute_solve()
    beauty_solve()
    #middle_solve()
