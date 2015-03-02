#!/usr/bin/python

import re
import zipfile

def getNext(number,text):
    match = re.compile(r'([0-9]+)')
    res = match.findall(text)
    return res[0] if len(res)>0 else ""

def goo():
    data = zipfile.ZipFile("channel.zip","r")
    print data.read("readme.txt")
    now = '90052'
    comments = ""
    while 1:
        text = data.read(now+".txt")
        comments += data.getinfo(now+".txt").comment
        now = getNext(now,text)
        print text+", next = "+now
        if now == "":
            break;
    print comments

if __name__=='__main__':
    goo()
