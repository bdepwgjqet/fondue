#!/usr/bin/python

#a = [1, 11, 21, 1211, 111221, 
#a[30]

import re

def parse_next(value):
    pc = ''
    ret = ""
    cnt = 0
    for c in value:
        if c==pc:
            cnt=cnt+1
            continue
        else:
            if pc!='':
                ret+=str(cnt)+pc
            pc=c
            cnt=1
    if pc!='':
        ret+=str(cnt)+pc
    return ret

def brute_solve():
    value = "1"
    for i in range(30):
        value = parse_next(value)
    print len(value)

def clean_parse_next(value):
    return "".join([str(len(m.group(0))) + m.group(1) for m in re.finditer(r"(\d)\1*", value)])

def clean_solve():
    value = "1"
    for i in range(30):
        value = clean_parse_next(value)
    print len(value)

if __name__=='__main__':
    #brute_solve()
    clean_solve()
