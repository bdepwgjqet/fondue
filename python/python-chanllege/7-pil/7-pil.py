#!/usr/bin/python

import urllib
from PIL import Image
import StringIO
import re

def f(v):
    return chr(int(v))

def goo():
    img = urllib.urlopen('http://www.pythonchallenge.com/pc/def/oxygen.png').read()
    img_data = Image.open(StringIO.StringIO(img))
    w,h = img_data.size
    row = [img_data.getpixel((i,h/2)) for i in range(0,w,7)]
    ords = [r for r,g,b,a in row if r==g==b]
    info = "".join(map(chr,ords))
    print info
    pattern = re.compile(r'([0-9]+)')
    match = pattern.findall(info)
    print "".join(map(f,match))

if __name__=='__main__':
    goo()
