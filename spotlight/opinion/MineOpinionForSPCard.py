#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re
from Topic import Topic


def process():
    if len(sys.argv) != 3:
        return

    pars = {}
    for arg in sys.argv:
        pair = (re.split('=|:', arg))
        if len(pair) > 1:
            pars[pair[0].lstrip('/')] = pair[1]

    ipath = pars["SampleInput"]
    opath = pars["SampleOutput"]

    ofile = open(opath, 'w')

    with open(ipath, 'r') as ifile:
        for line in ifile:
            try:
                cols = line.split('\t')
                if len(cols) != 9:
                    continue
                if not cols[7]:
                    continue
                if not cols[1]:
                    continue
                topic = Topic(cols[1], cols[3], cols[7])
                topic.mineopinion()
                fn = topic.firstopnum
                sn = topic.secondopnum
                if fn + sn <= 0:
                    continue
                #ofile.write(cols[7]+"\n")
                ofile.write(topic.topic + "\t" + topic.firstop + "\t" +
                            "%.2f"%(1.0*fn/(fn+sn)) + "\t" + topic.secondop +
                            "\t" + "%.2f"%(1.0*sn/(fn+sn)) + "\t" + topic.uri +"\n")
            except:
                continue

            #print "RES\t"+topic.topic + "\t" + topic.firstop + "\t" + \
            #            "%.2f"%(1.0*fn/(fn+sn)) + "\t" + topic.secondop + \
            #            "\t" + "%.2f"%(1.0*sn/(fn+sn)) + "\n"

if __name__ == '__main__':
    try:
        process()
    except Exception, e:
        sys.exit(0)
