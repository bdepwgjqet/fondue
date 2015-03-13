#!/usr/bin/python

import urllib
import cStringIO
import math
from PIL import Image

def hasframe(data):
    try:
        c = data.index(255)
    except ValueError:
        return False
    for x in data[c:c+20]:
        if x!=255:
            return False
    return True

def gao():
    url = 'http://kohsamui:thailand@www.pythonchallenge.com/pc/rock/beer2.png'; 
    data = list(Image.open(cStringIO.StringIO(urllib.urlopen(url).read())).getdata())

    grays = list(set(data))
    grays.sort()

    for i in grays[::-2]:
        data = map(lambda x:(x,255)[x==i-6],filter(lambda x:x<i-1,data))
        if hasframe(data):
            size = int(math.sqrt(len(data)))
            beer = Image.new("L",(size,size))
            beer.putdata(data)
            beer.convert('L').save('out'+str(i)+'.png')

    #gremlins 

if __name__=='__main__':
    gao()
