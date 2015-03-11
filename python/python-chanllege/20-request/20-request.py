#!/usr/bin/python

import urllib2
import httplib
from urllib2 import base64

def request(url,n):
    req = urllib2.Request(url = url,
            headers={'Range': 'bytes=%s-%s' %(n, n+1),'Authorization': 'Basic ' + base64.b64encode('butter:fly')})
    rsp = urllib2.urlopen(req)
    print rsp.read()
    print rsp.info()

def hack():
    url = 'http://www.pythonchallenge.com/pc/hex/unreal.jpg'
#    request(url,30203)
#    request(url,30237)
#    request(url,30284)
#    request(url,30295)
#    request(url,30313)
#    request(url,30347)
#    request(url,2123456789)
#    request(url,2123456743)
#    invader  1152983631
#   pwd : redavni
    conn = httplib.HTTPConnection("www.pythonchallenge.com")
    headers = {"Authorization": "Basic %s" % base64.b64encode('butter:fly')}
    headers["Range"] = "bytes=1152983631-1152983632"
    conn.request("GET","/pc/hex/unreal.jpg","",headers)
    rsp = conn.getresponse()
    h = open("data.zip","wb")
    h.write(rsp.read())
    h.close()

def gao():
    hack()

if __name__=='__main__':
    gao()
