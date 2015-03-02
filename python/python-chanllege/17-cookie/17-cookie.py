#!/usr/bin/python

import urllib
import re
import bz2
import xmlrpclib
import urllib2

def get_msg():
    uri = "http://www.pythonchallenge.com/pc/def/linkedlist.php?busynothing=%s"
    next_re = re.compile("is (\d+)")
    cookie_re = re.compile("info=([^;]+);")
    result = []

    now = "12345"

    while True:
        h = urllib.urlopen(uri % now)
        print uri % now
        val = h.read()
        cookie = h.info().getheader("Set-Cookie")
        h.close()

        cookie_val = cookie_re.search(cookie)

    #    print cookie
    #    print cookie_val
    #    print val

        if cookie and cookie_val:
            result.append(urllib.unquote_plus(cookie_val.group(1)))

        try:
            now = next_re.search(val).group(1)
        except:
            break

#    print bz2.decompress("".join(result))
    print bz2.decompress("".join(result))

def brute_solve():

    #msg: the flowers are on their way
    #get_msg()

    conn = xmlrpclib.ServerProxy("http://www.pythonchallenge.com/pc/phonebook.php")

    #555-VIOLIN
    print conn.phone("Leopold")

    uri = "http://www.pythonchallenge.com/pc/stuff/violin.php" 
    msg = "the flowers are on their way"
    req = urllib2.Request(
            uri, headers = {"Cookie": "info="+urllib.quote_plus(msg)}
        )
    print urllib2.urlopen(req).read()

if __name__=='__main__':
    brute_solve()
