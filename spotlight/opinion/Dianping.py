#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re
import operator
from difflib import SequenceMatcher

pre = ""

for line in sys.stdin:
    """
    line = line.rstrip('\n')
    cols = line.split('\t')
    if len(cols) != 9:
        pre = pre + line
        if len(pre.split('\t')) == 9:
            print pre
            pre = ""
        elif len(pre.split('\t')) > 9:
            print "ERROR"
            pre = ""
    else:
        print line
    """

    cols = line.split('\t')
    city = cols[0]
    title = cols[1]
    hot = cols[2]
    url = cols[3]

    # tag
    tags = cols[8].split("/")
    tagv = {}
    for tag in tags:
        tag = tag.strip()
        score = re.findall(r"(\d+)", tag)
        mark = re.findall(r"(.*?)\(", tag)
        score = int(score[0]) if len(score) > 0 else 0
        mark = mark[0] if len(mark) > 0 else 0
        if mark:
            tagv[mark] = score
        #print tag, score, mark
    sorted_tagv = sorted(tagv.items(), key=operator.itemgetter(1), reverse=True)
    curtag = ",".join([mk for (mk, sc) in sorted_tagv][0:5])

    #comment process
    comments = cols[7]
    comments = re.split(',|\.|。|，|###SEP###|！', comments)
    comments = [c.strip() for c in comments if c]
    reskey = ['口味', '口感', '服务', '味道', '价格', '价钱', '上菜', '环境', '位置', '设施', '接待', '风格', '菜品']
    ucomments = []
    for c in comments:
        for key in reskey:
            if key in c:
                ucomments.append(c)
                break
    cdic = {}
    for c1 in ucomments:
        cscore = 0
        for c2 in ucomments:
            c1c2similarp = SequenceMatcher(None, c1, c2).ratio()
            if c1c2similarp > 0.2:
                cscore += 1
        cdic[c1] = cscore
    sorted_cdic = sorted(cdic.items(), key=operator.itemgetter(1), reverse=True)
    #for k,v in sorted_cdic:
    #    print k,v
    topcom = [com for com, sc in sorted_cdic][0:5]
    topcomdis = []
    vis = set()
    for i in range(0, len(topcom)):
        if i in vis:
            continue
        cur = topcom[i]
        topcomdis.append(cur)
        for j in range(i+1, len(topcom)):
            if j in vis:
                continue
            nx = topcom[j]
            sim = SequenceMatcher(None, cur, nx).ratio()
            if sim > 0.5:
                vis.add(j)
    bestcom = ",".join(topcomdis)



    print "%s\t%s\t%s\t%s\t%s\t%s" % (city, title, hot, url, curtag, bestcom)
