#!/usr/bin/python

import urllib
import re

#12345
#16044/2
#63579 
#peak.html

def brute_solve():

    base_url = "http://www.pythonchallenge.com/pc/def/linkedlist.php"
    next_url = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing=63579"
    
    for i in range(401):
        html = urllib.urlopen(next_url)
        text = html.read()
        pattern = re.compile(r'([0-9]+)')
        next_url = base_url+"?nothing="+pattern.findall(text)[0]
        print next_url

if __name__=='__main__':    
    brute_solve()
