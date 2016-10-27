#!/usr/bin/env python
# -*- coding: utf-8 -*-

import urllib2
import json

def collect(feed, page):
    heros = []
    for i in range(0, page):
        cur = feed.strip() + "&page=" + str(i+1)
        print cur
        response = urllib2.urlopen(cur)
        res = response.read()
        res = json.loads(res)
        thispage = res["equip_list"]
        heros = heros + thispage
    return heros

