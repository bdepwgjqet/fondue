#!/usr/bin/python

import urllib
from PIL import GifImagePlugin
import string
import bz2
from PIL import Image

def fetch_gif():
    urllib.urlretrieve("http://www.pythonchallenge.com/pc/hex/zigzag.gif","zigzag.gif")

def gg():
    zig = GifImagePlugin.GifImageFile(u'zigzag.gif')
    zigdata = zig.tostring()
    print "".join(['%X'%(ord(i),) for i in zigdata[:10]])

    print len(zig.getcolors())
    palette = zig.palette.getdata()[1][::3]
    print ''.join(['%X'%(ord(i),) for i in palette[:10]])

    t=string.maketrans(''.join([chr(i) for i in range(256)]),palette)
    zigtrans=zigdata.translate(t)
    print ''.join(['%X'%(ord(i),) for i in zigtrans[:10]])

    print zigdata[1:]==zigtrans[:-1]
    deltas=filter(lambda p:p[0]!=p[1],zip(zigdata[1:],zigtrans[:-1]))
    diffs=[''.join([p[i] for p in deltas]) for i in range(2)]
    print diffs[0][:20]
    print diffs[1][:20]

    bz=bz2.BZ2Decompressor().decompress(diffs[0])
    bz=bz2.decompress(diffs[0])
    print len(bz)
    print bz[:100]

    keywords=bz.split(' ')
    keys={}
    for k in keywords: keys[k]=1
    print keys.keys()

    print len(keywords)
    print len(keys.keys())
    print len(keywords)/len(keys.keys())

    im=Image.new('1',zig.size,0)
    im.putdata([ p[0]==p[1] for p in zip(zigdata[1:],zigtrans[:-1])])
    im.save("out.png")

    # repeat switch

def gao():
#   fetch_gif()
    gg()


if __name__=='__main__':
    gao()
