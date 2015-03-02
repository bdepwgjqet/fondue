#!/usr/bin/python

from calendar import isleap
from datetime import date

def brute_solve():
    for year in range(1006,2000,10):
        t = date(year,1,27)
        if isleap(year) and t.weekday() == 1: #TUESDAY
            print t.isoformat()

#1756-1-27 mozart's birthday

if __name__=='__main__':
    brute_solve()
