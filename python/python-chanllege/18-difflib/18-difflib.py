#!/usr/bin/python

import gzip
import difflib
import binascii

def brute_solve():
    data = gzip.open('deltas.gz')
    diff = difflib.Differ()

    p1, p2 = [], []
    f1 = f2 = f3 = ''

    for line in data:
        p1.append(line[0:53])
        p2.append(line[56:-1])
    data.close()

    diff_list = list(diff.compare(p1,p2))

    for line in diff_list:
        if line[0] == '+':
            f1 += line[2:].replace(" ",'')
        elif line[0] == '-':
            f2 += line[2:].replace(" ",'')
        else:
            f3 += line[2:].replace(" ",'')

    p1 = open('pic1.png','wb')
    p1.write(binascii.unhexlify(f1))
    p1.close()

    p2 = open('pic2.png','wb')
    p2.write(binascii.unhexlify(f2))
    p2.close()

    p3 = open('pic3.png','wb')
    p3.write(binascii.unhexlify(f3))
    p3.close()


if __name__=='__main__':
    brute_solve()
