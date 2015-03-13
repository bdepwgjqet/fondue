#!/usr/bin/python

import urllib
import cStringIO
from PIL import Image

def mandelbrot(l = 0.34, b = 0.57, w = 0.036, h = 0.027, max = 128, size=(640,480)):
    xstep = w / size[0]
    ystep = h / size[1]
    for y in xrange(size[1]-1, -1, -1):
        for x in xrange(size[0]):
            c = complex(l+x*xstep, b + y*ystep)
            z = 0+0j
            for i in xrange(max):
                z = z*z + c
                if abs(z) > 2:
                    break
            yield i

def gao():
    url = 'http://kohsamui:thailand@www.pythonchallenge.com/pc/rock/mandelbrot.gif' 
    img = Image.open(cStringIO.StringIO(urllib.urlopen(url).read()))
    mandel = img.copy()
    mandel.putdata(list(mandelbrot()))
    mandel.save('out.png')

    differences = [(a-b) for a,b in zip(img.getdata(),mandel.getdata()) if a != b]
    print len(differences)
    print set(differences)

    plot = Image.new('L',(23,73))
    plot.putdata([(i<16) and 255 or 0 for i in differences])
    plot.convert('L').save('result.png')

    #arecibo

if __name__=='__main__':
    gao()
