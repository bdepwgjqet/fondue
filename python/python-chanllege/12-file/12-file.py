#!/usr/bin/python

import urllib

def brute_solve():
    f = open('evil2.gfx','rb').read()
    for i in range(5):
        open("image"+str(i)+".img","wb").write(f[i::5])

if __name__=='__main__':
    brute_solve()
