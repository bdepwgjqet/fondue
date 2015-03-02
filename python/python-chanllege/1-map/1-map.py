#!/usr/bin/python

import string

def brute_solve(s):
    ret = ""
    for c in s:
        if c==' ' or c == "." or c=="(" or c==")" or c=='\'':
            ret+=c
        elif c=='y':
            ret+='a'
        elif c=='z':
            ret+='b'
        else:
            ret+=chr(ord(c)+2)
    return ret

def beautiful_solve(s):
    table = string.maketrans(string.ascii_lowercase,string.ascii_lowercase[2:]+string.ascii_lowercase[:2])
    return s.translate(table)

if __name__=='__main__':
    s = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."
    #s="map"
#    print brute_solve(s)
    print beautiful_solve(s)
