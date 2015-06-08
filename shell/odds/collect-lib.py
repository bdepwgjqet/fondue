#!/usr/bin/python

import re

def get_size(text):
    pattern = re.compile(r'Size :[ ]*(\d*.{1}\d*) KiB')
    match = pattern.findall(text)
    return float(match[0])

def get_name(text):
    pattern = re.compile(r': (.*?) Installed')
    match = pattern.findall(text)
    return match[0]

if __name__=='__main__':

    file_name = "output"
    f = open(file_name)
    text = f.read().rstrip('\n')
    t_arr = text.split('\n')
    ret = 0.0
    for t in t_arr:
        v = get_size(t)
        ret += v
        if v > 20000:
            print get_name(t)+' '+str(v)
    print ret
