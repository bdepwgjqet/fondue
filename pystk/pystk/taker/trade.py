#!/usr/bin/env python
# -*- coding: utf-8 -*-


import time
from conf import trans_api
from urllib2 import urlopen, Request


def trade_inf(symbol=None, date=None, retry=3, pause=0.01):
    if symbol is None or len(symbol) != 6 or date is None:
        return None

    symbol = _generalize_symbol(symbol)

    for tr in range(retry):
        time.sleep(pause)
        try:
            rs = Request(trans_api % (date, symbol))
            rsd = urlopen(rs, timeout=10).read()
            rsd = rsd.decode('GBK')
        except Exception as e:
            print (e)
        else:
            return rsd


def _generalize_symbol(symbol):
    if len(symbol) != 6:
        return ''
    else:
        return 'sh%s' % symbol if symbol[:1] in ['5', '6', '9'] else 'sz%s' % symbol
