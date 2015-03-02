#!/usr/bin/python

import urllib
from PIL import Image
import StringIO

def brute_solve():
    img = urllib.urlopen('http://www.pythonchallenge.com/pc/return/wire.png').read()
    img_data = Image.open(StringIO.StringIO(img))
    des = Image.new('RGB',(100,100))
    ex,ey = -1,0
    sx,sy = 0,0
    d = (1,0),(0,1),(-1,0),(0,-1)
    c = 100
    v = 0
    ind = 0
    while c > 0:
        c -= v
        v = v^1
        dx,dy = d[ind]
        ind = (ind+1)%4
        for i in range(c):
            ex += dx
            ey += dy
            des.putpixel((ex,ey),img_data.getpixel((sx,sy)))
            sx += 1
    des.save("ret.png","PNG")


if __name__=='__main__':
    brute_solve()
