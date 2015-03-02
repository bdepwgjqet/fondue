#!/usr/bin/python

import xmlrpclib

def brute_solve():
    xmlrpc = xmlrpclib.ServerProxy('http://www.pythonchallenge.com/pc/phonebook.php')
#    print xmlrpc.system.listMethods()
#    print xmlrpc.system.methodHelp('phone')
    print xmlrpc.phone('Bert')

if __name__=='__main__':
    brute_solve()
