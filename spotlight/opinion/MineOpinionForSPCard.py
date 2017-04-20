#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import re
import traceback
import zipfile
from Topic import Topic


def process():
    print(len(sys.argv))
    if len(sys.argv) != 4:
        return

    pars = {}
    for arg in sys.argv:
        pair = (re.split('=|:', arg))
        if len(pair) > 1:
            pars[pair[0].lstrip('/')] = pair[1]

    ipath = pars["SampleInput"]
    opath = pars["SampleOutput"]
    models = pars["models"]

    sentvocab = "./models/2class/vocab"
    emomodel = "./models/emotion"
    vectorfile = "./models/trained-vec.pkl"

    print(ipath, opath, vectorfile, models)

    with zipfile.ZipFile(models, "r") as zip_ref:
        zip_ref.extractall("./")

    ofile = open(opath, 'w', encoding="utf8")

    topicdic = dict()
    try:
        ifile = open(ipath, 'r', encoding="utf8")
        lines = ifile.readlines()
        print(len(lines))
        for line in lines:
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
    else:
        ifile.close()

    for tid in sorted(topicdic):
        try:
            topic = topicdic[tid]
            if len(topic.comments) < 20:
                continue
            topic.mineopinion(vectorfile)
            topic.minesentiment(sentvocab)
            topic.mineemotion(emomodel)

            # sentiment result str
            posrate = "正面:{:.1%}".format(1.0*topic.positive/topic.ttlsentiment)
            negrate = "负面:{:.1%}".format(1.0*topic.negtive/topic.ttlsentiment)
            sentstr = posrate + "\t" + negrate
            print(sentstr.encode('utf8'))

            emostr = ""
            for idx in range(0, len(topic.emolist)):
                cidx = (idx + 1) % len(topic.emolist)
                if emostr:
                    emostr += "　"
                emo = topic.emolist[cidx]
                weight = topic.emoweight[cidx]
                currate = "{:.1%}".format(1.0*weight/topic.ttlemotion)
                emostr += emo + ":" + currate
            print(emostr.encode('utf8'))

            #opinion result str
            tw = topic.totalopweight
            if tw <= 0.0:
                continue
            opstr = ""
            for i in range(len(topic.mainop)):
                if i >= 5:
                    break
                op = topic.mainop[i]
                curid = topic.mainopids[i]
                cursent = 'M'
                if curid >= 0 and curid < len(topic.sentiments_y):
                    cursent = topic.sentiments_y[curid]
                if opstr:
                    opstr += ".　　"
                opstr += str(i+1) + "."
                opstr += op.sentence + " {0} ".format(cursent) + "{:.1%}".format(op.sumweight/tw)
            opstr = opstr + "\t" + sentstr + "\t" + emostr
            print(opstr.encode('utf8'))
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
