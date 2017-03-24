#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re
import traceback
from Topic import Topic


def process():
    if len(sys.argv) != 5:
        return

    pars = {}
    for arg in sys.argv:
        pair = (re.split('=|:', arg))
        if len(pair) > 1:
            pars[pair[0].lstrip('/')] = pair[1]

    ipath = pars["SampleInput"]
    opath = pars["SampleOutput"]
    vectorfile = pars["trainedvec"]
    vocab = pars["vocab"]

    print(ipath, opath, vectorfile)

    ofile = open(opath, 'w')

    topicdic = dict()

    with open(ipath, 'r') as ifile:
        for line in ifile:
            try:
                cols = line.split('\t')
                if len(cols) != 11:
                    continue
                if not cols[8]:
                    continue
                if not cols[2]:
                    continue
                if not cols[0]:
                    continue
                if cols[0] not in topicdic:
                    topicdic[cols[0]] = Topic(cols[2])
                curtopic = topicdic[cols[0]]
                curtopic.insertcomment(cols[4], cols[8], cols[9])
                topicdic[cols[0]] = curtopic
            except:
                traceback.print_exc(file=sys.stdout)
                continue

    for tid, topic in topicdic.items():
        try:
            if len(topic.comments) < 20:
                continue
            topic.mineopinion(vectorfile)
            topic.minesentiment(vocab)
            posrate = "{:.1%}".format(1.0*topic.positive/topic.ttlsentiment)
            negrate = "{:.1%}".format(1.0*topic.negtive/topic.ttlsentiment)
            print(posrate,negrate)
            tw = topic.totalopweight
            if tw <= 0.0:
                continue
            opstr = ""
            for i in range(len(topic.mainop)):
                if i >= 5:
                    break
                op = topic.mainop[i]
                if opstr:
                    opstr += ".　　"
                opstr += str(i+1) + "."
                opstr += op.sentence + " " + "{:.1%}".format(op.sumweight/tw)
            opstr = opstr + "\t" + posrate + "\t" + negrate
            print(opstr)
            show = topic.topic + "\t" + opstr + "\t" + ";".join(topic.uri) + "\n";
            ofile.write(show)
        except:
            traceback.print_exc(file=sys.stdout)
            continue

if __name__ == '__main__':
    try:
        process()
    except:
        sys.exit(0)
