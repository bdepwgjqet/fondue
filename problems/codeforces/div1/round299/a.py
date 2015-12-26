#!/usr/bin/python

import math

def ca(l,r):
    return (l + r) * (r - l + 1) / 2

A, B, n = map(int, raw_input().split())

ret = []

for i in xrange(n):
    l, t, m = map(int, raw_input().split())
    if A + B * (l - 1) > t:
        ret.append(-1)
        continue
    r = (t - A) / B + 1
    D = (B-2*A)*(B-2*A)-4*B*(-2*l*A+2*A-B*(l-2)*(l-1)-2*m*t)
    r2 = int(((B-2*A) + math.sqrt(D)) / 2 / B)
    ret.append(min(r,r2))

print "\n".join(map(str,ret))
