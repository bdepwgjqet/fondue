#!/usr/bin/python

import zlib
import bz2

def gao():
    f1 = 'x\x9c'
    f2 = 'BZh'
    f3 = '\x9cx'
    z = open('package.pack','rb')
    s = z.read()
    ret = []
    while True:
        if s.startswith(f1):
            s = zlib.decompress(s)
            ret.append(' ')
        elif s.startswith(f2):
            s = bz2.decompress(s)
            ret.append('#')
        elif s.endswith(f3):
            s = s[::-1]
            ret.append('\n')
        else:
            break
    print ''.join(ret)

if __name__=='__main__':
    gao()
