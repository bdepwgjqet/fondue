#!/usr/bin/python

import re

def brute_solve(s):
    pattern = re.compile(r'[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]')
    return "".join(pattern.findall(s))

if __name__=='__main__':    
    file = open('3.in')
    s = file.read()
    print brute_solve(s)
