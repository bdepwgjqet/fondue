#!/usr/bin/python

import urllib
import re
from PIL import Image

def gao():
    url = 'http://repeat:switch@www.pythonchallenge.com/pc/ring/yankeedoodle.csv'
    data = re.findall(r'[\d.]+',urllib.urlopen(url).read())
    img = Image.new('F',(53,139))
    img.putdata(map(float,data), 256)
    img = img.transpose(Image.ROTATE_270)
    img = img.transpose(Image.FLIP_LEFT_RIGHT)
    img.convert('L').save('out.png')

    result = []
    for i in xrange(0,len(data)-2,3):
        result.append(chr(int(data[i][5]+data[i+1][5]+data[i+2][6])))
    print ''.join(result)

if __name__=='__main__':
    gao()
