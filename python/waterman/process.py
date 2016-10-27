#!/usr/bin/env python
# -*- coding: utf-8 -*-

import crawl

def process():
    feedf = open('feed.in', 'r')
    for feed in feedf.readlines():
        heros = crawl.collect(feed, 1)

if __name__=='__main__':
    process()
