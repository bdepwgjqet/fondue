#!/usr/bin/python

import urllib
import bz2

def gao():
    url = 'http://www.pythonchallenge.com/pc/ring/guido.html'
    html = urllib.urlopen(url).read()
    arr = html.split('\n')
    white = [l for l in arr if len(l.strip())==0]

    msg = ''.join(chr(len(l)) for l in white)

    result = bz2.decompress(msg)
    print result

if __name__=='__main__':
    gao()
