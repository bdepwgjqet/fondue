#!/usr/bin/python

import urllib
import StringIO
from PIL import Image
from PIL import ImageDraw
from PIL import ImageSequence

def get_pic():
    img = urllib.urlopen('http://www.pythonchallenge.com/pc/hex/white.gif').read()
    f = file('white.gif','wb')
    f.write(img)
    f.close()

def gao():
    get_pic()
    img = Image.open("white.gif")
    new = Image.new("RGB",(200,200))
    draw = ImageDraw.Draw(new)
    cx , cy = 0, 0
    for s in ImageSequence.Iterator(img):
        l,u,r,d = img.getbbox()
        dx = (l-100)
        dy = (u-100)
        cx += dx
        cy += dy
        if dx==dy==0:
            cx+=30
            cy+=30
        draw.point([cx,cy])

    new.save('out.png')

if __name__=='__main__':
    gao()
