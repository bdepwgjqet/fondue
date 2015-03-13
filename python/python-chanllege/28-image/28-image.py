#!/usr/bin/python

from cStringIO import StringIO
import urllib
from PIL import Image

def paired(data):
    data = iter(data)
    while True:
        yield data.next(), data.next()

def gao():
    url = 'http://repeat:switch@www.pythonchallenge.com/pc/ring/bell.png'
    bell = Image.open(StringIO(urllib.urlopen(url).read()))
    green = bell.split()[1]
    message = ""
    for a,b in paired(green.getdata()):
        diff = abs(a-b)
        if diff != 42:
            message += chr(diff)
    print message

    who = "Guido Van Rossum"
    print who.split()[0]

if __name__=='__main__':
    gao()
