#!/usr/bin/python

import wave
import urllib
from PIL import Image

def gao():
    template = "http://butter:fly@www.pythonchallenge.com/pc/hex/lake%i.wav"
    fname = 'lake%d.wav'
    for i in range(1,26):
        urllib.urlretrieve(template % i, fname % i)

    l = []

    for i in range(1,26):
        f = wave.open(u'lake%d.wav'%i,'rb')
        l.append(f.readframes(f.getnframes()))
        f.close()

    im = Image.new('RGB',(300,300))
    for i in range(25):
        im.paste(Image.fromstring("RGB",(60,60),l[i]),(60*(i%5),60*(i//5)))
    im.save('out.png')

if __name__=='__main__':
    gao()
