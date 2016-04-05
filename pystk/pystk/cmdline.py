#!/usr/bin/env python
# -*- coding: utf-8 -*-

from taker import trade
from saver import save
import sys
import time


def execute():
    reload(sys)
    sys.setdefaultencoding("utf-8")

    with open("symbol.out") as f:
        symbols = f.readlines()
    today = time.strftime("%Y-%m-%d")
    print 'Hi, Please input the date you want (default to be %s):' % today
    date = raw_input()
    if date is '':
        date = time.strftime("%Y-%m-%d")
    for symbol in symbols:
        print 'Fetching ' + symbol
        time.sleep(5)
        symbol = symbol.strip()
        path = "output/" + symbol + ".xls"
        try:
            s = trade.trade_inf(symbol, date)
        except ValueError as e:
            print e.message
            print 'Please Contact the author, thanks :)'
            return
        s = [[y for y in x.split('\t')] for x in s.split('\n')]
        save.save_to_xls(s, path)
    raw_input('Press any key to exit.')


if __name__ == '__main__':
    execute()
