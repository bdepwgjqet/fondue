#!/usr/bin/env python
# -*- coding: utf-8 -*-

from Jieba import JiebaInvoker
from difflib import SequenceMatcher
import operator
from optfidf import Predict as TfidfPredict
from evalsentiment import predict as predictsent

class Opinion(object):

    def __init__(self, core, weight):
        self.core = core
        self.sentence = ""
        self.sentence_comb = []
        self.rawsent = ""
        self.around = []
        self.weight = weight
        self.tweight = 0.0
        self.sumweight = 0.0
        self.percent = 0.0

    def check_word_comb(self, lgl, sml):
        for c in sml:
            if c not in lgl:
                return False
        return True

    def gensentence(self, wordweight):
        self.sentence = ""
        self.rawsent = ""
        issent = False
        rcore = ""
        rcorescore = 0
        for (k,v) in self.around[0:-1]:
            self.rawsent += k
            self.sentence += k
            self.sentence_comb.append(v)
            if v in ['v', 'd']:
                issent = True
            if k in wordweight:
                self.tweight += self.weight*wordweight[k]
                if wordweight[k] > rcorescore:
                    rcorescore = wordweight[k]
                    rcore = k
        if self.check_word_comb(self.sentence_comb, ['a', 'uj']):
            issent = True

        self.rawsent += self.core
        self.sentence += self.core

        if issent == False:
            self.sentence = ""

        self.core = rcore

class Topic(object):

    def __init__(self, topic):
        self.topic = topic
        self.comments = []
        self.jbcomments = []
        self.firstop = ""
        self.secondop = ""
        self.totalopweight = 0
        self.firstopnum = 0
        self.secondopnum = 0
        self.positive = 0
        self.negtive = 0
        self.uri = []
        self.agreedic = dict()
        self.corewords = dict()
        self.mainop = []

    def insertcomment(self, url, content, agree):
        if url not in self.uri:
            self.uri.append(url)
        self.comments.append(content)
        if content:
            jbinvoker = JiebaInvoker(content)
            pars = jbinvoker.cut()

            words = []

            for k,v in pars:
                words.append((k, v))
            self.jbcomments.append(words)
        cagree = 1
        try:
            cagree = 1 + int(agree)
        except:
            cagree = 1
        if content not in self.agreedic:
            self.agreedic[content] = 0

        self.agreecnt = self.agreedic[content]
        self.agreecnt += cagree
        self.agreedic[content] = self.agreecnt

    def minesentiment(self, vocab_path):
        self.positive = 0
        self.negtive = 0
        self.ttlsentiment = 0
        x_raw = []
        for words in self.jbcomments:
            comment = " ".join([x for x,y in words])
            x_raw.append(comment)
        y = predictsent(x_raw, vocab_path, checkpoint_dir="./models/2class/checkpoints")
        self.sentiments_y = []
        for idx in range(len(self.comments)):
            cmt = self.comments[idx]
            cweight = self.agreedic[cmt]
            if y[idx] > 0.5:
                self.positive += cweight
                self.sentiments_y.append('P')
            else:
                self.negtive += cweight
                self.sentiments_y.append('N')
            self.ttlsentiment += cweight

    def mineemotion(self, model_path):
        self.emolist = ["其它", "高兴", "愤怒", "厌恶", "难过", "恐惧", "惊奇"]
        self.emoweight = [0, 0, 0, 0, 0, 0, 0]
        self.ttlemotion = 0
        x_raw = []
        for words in self.jbcomments:
            comment = " ".join([x for x,y in words])
            x_raw.append(comment)
        y = predictsent(x_raw, model_path + "/vocab", checkpoint_dir= model_path + "/checkpoints")
        for idx in range(len(self.comments)):
            cmt = self.comments[idx]
            cweight = self.agreedic[cmt]
            self.emoweight[int(y[idx])] += cweight
            self.ttlemotion += cweight

        #hack for happy
        #self.emoweight[0] += self.emoweight[1]
        #self.emoweight[1] = 0

    def minecorewords(self, vectorfile):
        contents = []
        content = []
        for comment in self.jbcomments:
            content.append(" ".join([x for x,v in comment]))
        contents.append(" ".join([x for x in content]))
        corekeys = TfidfPredict(contents, vectorfile)
        if len(corekeys) > 0:
            corewords = dict()
            for k,v in corekeys[0]:
                corewords[k] = v
            return corewords
        return dict()


    def mineopinion(self, vectorfile):
        self.corewords = self.minecorewords(vectorfile)

        opcans = []
        corewordfreq = {}
        for i in range(0,len(self.jbcomments)):
            jbc = self.jbcomments[i]
            rawcomment = self.comments[i]
            if rawcomment not in self.agreedic:
                print("ERROR, comment not found." + rawcomment)
            cweight = self.agreedic[rawcomment]
            l = 0
            r = 0
            curaround = []

            if len(jbc) >= 30:
                continue

            while r < len(jbc):

                if jbc[r][1] in ['x']:
                    r = r + 1
                    l = r
                    curaround = []
                    continue

                if len(curaround)<=0 and jbc[r][1] in ['uj', 'c']:
                    r = r + 1
                    l = r
                    curaround = []
                    continue

                curaround.append((jbc[r][0], jbc[r][1]))

                #if (jbc[r][1] in ['n', 'ns', 'vn', 'nr', 'nt', 'an'] and r > l + 3) or \
                if (r+1 < len(jbc) and jbc[r+1][1] in ['x'] and r-l+1<10 and r-l+1>3)\
                    or (r+1 == len(jbc) and r-l+1<10 and r-l+1>3):

                    curop = Opinion(jbc[r][0], cweight)
                    curop.around = curaround
                    curop.gensentence(self.corewords)
                    if curop.sentence:
                        opcans.append(curop)

                    curaround = []
                    l = r + 1
                r += 1

        oplist = self.clusterop(opcans)
        opboard = sorted(oplist, key=lambda x: x.sumweight, reverse=True)
        self.totalopweight = 0
        for op in opboard:
            self.totalopweight += op.sumweight
        curttlweight = 0.0
        if self.totalopweight <= 0.0:
            return
        for op in opboard:
            if curttlweight/self.totalopweight < 0.6 or len(self.mainop) < 2:
                self.mainop.append(op)
            curttlweight += op.sumweight 
        self.mainopids = []
        for op in self.mainop:
            curid = -1
            for idx in range(len(self.comments)):
                comment = self.comments[idx]
                if op.sentence in comment:
                    curid = idx
                    break
            self.mainopids.append(curid)

            
    #to improve
    def clusterop(self, opcans):
        group = []
        for i in range(len(opcans)):
            group.append(i)
        for i in range(len(opcans)):
            op = opcans[i]
            for j in range(i+1, len(opcans)):
                nop = opcans[j]
                if self.similarity(nop.sentence.encode('utf-8'), op.sentence.encode('utf-8')):
                    #print(i,j,group[i],group[j])
                    for k in range(len(opcans)):
                        if group[k] == group[i] or group[k] == group[j]:
                            group[k] = min(group[i], group[j])

        clusteredops = []
        idtogroup = dict()
        for i in range(len(opcans)):
            if group[i] not in idtogroup:
                idtogroup[group[i]] = []
            idtogroup[group[i]].append(opcans[i])
        for k in idtogroup:
            v = idtogroup[k]
            mxscore = 0
            sumscore = 0
            mxidx = 0
            for idx in range(len(v)):
                op = v[idx]
                sumscore += op.tweight
                if mxscore < op.tweight:
                    mxscore = op.tweight
                    mxidx = idx
            v[mxidx].sumweight = sumscore
            clusteredops.append(v[mxidx])
        return clusteredops


    def ranktopop(self, opcans, coreword):

        if len(opcans) <= 0:
            return ("", 0)

        op = ""
        num = 0
        sentfreq = {}

        for op in opcans:
            if op.core == coreword:
                sentfreq[op.sentence] = 0
                num += 1
        for (k,v) in sentfreq.iteritems():
            for op in opcans:
                if self.similarity(k.encode('utf-8'), op.sentence.encode('utf-8')):
                    v = v + op.tweight
            sentfreq[k] = v
        sorted_cans = sorted(sentfreq.items(), key=operator.itemgetter(1),
                             reverse=True)
        return (sorted_cans[0][0].encode('utf-8'), sorted_cans[0][1])

    def recalcularopnum(self, opcans):
        self.firstopnum = 0
        self.secondopnum = 0
        for op in opcans:
            if self.similarity(self.firstop, op.sentence.encode('utf-8')):
                self.firstopnum += op.tweight
                print(self.firstopnum,op.sentence.encode('utf-8'), op.tweight)
            if self.similarity(self.secondop, op.sentence.encode('utf-8')):
                self.secondopnum += op.tweight
                print(self.secondopnum,op.sentence.encode('utf-8'), op.tweight)

    def similarity(self, a, b):
        similarp = SequenceMatcher(None, a, b).ratio()
        #print a, b, similarp

        if similarp > 0.58:
            return True
        return False
