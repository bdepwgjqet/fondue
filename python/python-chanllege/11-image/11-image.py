#!/usr/bin/python

from PIL import Image
import urllib
import StringIO

#us:huge pw:file

def show_pic(img,st):
    w,h = img.size
    new_img = Image.new(img.mode,(w/2,h/2))
    for i in range(st,w,2):
        for j in range(st,h,2):
            new_img.putpixel((i/2,j/2),img.getpixel((i,j)))
    new_img.save("result"+str(st)+".png","PNG")

def brute_solve():
    img = urllib.urlopen('http://www.pythonchallenge.com/pc/return/cave.jpg').read()
    img_data = Image.open(StringIO.StringIO(img))
    show_pic(img_data,0)
    show_pic(img_data,1)

if __name__=='__main__':
    brute_solve()
