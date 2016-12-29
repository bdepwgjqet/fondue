#!/usr/bin/env python
# -*- coding: utf-8 -*-

from Jieba import JiebaInvoker
from difflib import SequenceMatcher
import operator

class Opinion(object):

    def __init__(self, core):
        self.core = core
        self.sentence = ""
        self.sentence_comb = []
        self.rawsent = ""
        self.around = []
        self.weight = 0

    def check_word_comb(self, lgl, sml):
        for c in sml:
            if c not in lgl:
                return False
        return True

    def gensentence(self):
        self.sentence = ""
        self.rawsent = ""
        issent = False
        for (k,v) in self.around[0:-1]:
            self.rawsent += k
            #if v in ['r','y','a','v', 'd', 'vn', 'b', 'uj', 'n', 'ns', 'vn', 'nr', 'nt', 'an']:
            self.sentence += k
            self.sentence_comb.append(v)
            if v in ['v', 'd']:
                issent = True
            #else:
            #    self.sentence = ""
            #    self.sentence_comb = []
            #    issent = False
        if self.check_word_comb(self.sentence_comb, ['a', 'uj']):
            issent = True

        self.rawsent += self.core
        self.sentence += self.core
        if issent == False:
            self.sentence = ""

class Topic(object):

    def __init__(self, topic, uri, cmts):
        self.topic = topic
        self.uri = uri
        self.firstop = ""
        self.secondop = ""
        self.firstopnum = 0
        self.secondopnum = 0
        self.comments = cmts.split('###SEP###')
        self.jbcomments = []
        for comment in self.comments:
            if not comment:
                continue
            jbinvoker = JiebaInvoker(comment)
            pars = jbinvoker.cut()

            words = []

            for k,v in pars:
                words.append((k, v))
            self.jbcomments.append(words)



    def mineopinion(self):

        opcans = []
        wordfreq = {}
        for jbc in self.jbcomments:
            l = 0
            r = 0
            curaround = []

            #wlist = [x[0] for x in jbc]
            #print "".join(wlist).encode('utf-8')
            #for (k,v) in jbc:
            #    print k.encode('utf-8') + "\t" + v.encode('utf-8')

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

                if (jbc[r][1] in ['n', 'ns', 'vn', 'nr', 'nt', 'an'] and r > l + 3)\
                    or (r+1 < len(jbc) and jbc[r+1][1] in ['x'] and r-l+1<10 and r-l+1>3)\
                    or (r+1 == len(jbc) and r-l+1<10 and r-l+1>3):

                    curop = Opinion(jbc[r][0])
                    curop.around = curaround
                    curop.weight = 1
                    curop.gensentence()
                    if curop.sentence:
                        opcans.append(curop)
                        if curop.core in wordfreq:
                            wordfreq[curop.core] = wordfreq[curop.core] + 1
                        else:
                            wordfreq[curop.core] = 1
                    #print curop.sentence.encode('utf-8'), curop.rawsent.encode('utf-8'),"====>"

                    curaround = []
                    l = r + 1
                r += 1
#
        sorted_freq = sorted(wordfreq.items(), key=operator.itemgetter(1),
                             reverse=True)

        '''
        for op in opcans:
            print op.sentence.encode('utf-8'), op.rawsent.encode('utf-8')

        for (k, v) in sorted_freq:
            print k.encode('utf-8'), v
        '''

        opfreq = {}
        for (k, v) in sorted_freq:
            (op, cnt) = self.generateop(opcans, k)
            opfreq[op] = cnt

        sorted_opfreq = sorted(opfreq.items(), key=operator.itemgetter(1),
                               reverse=True)
        if len(sorted_opfreq) > 0:
            self.firstop, self.firstopnum = sorted_opfreq[0]
            for (k,v) in sorted_opfreq[1:]:
                if (self.similarity(self.firstop, k) == False):
                    self.secondop, self.secondopnum = k,v
                    self.recalcularopnum(opcans)
                    break
        #print self.firstop, self.firstopnum, self.secondop, self.secondopnum

    def generateop(self, opcans, coreword):

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
                    v = v + 1
            sentfreq[k] = v
        sorted_cans = sorted(sentfreq.items(), key=operator.itemgetter(1),
                             reverse=True)
        return (sorted_cans[0][0].encode('utf-8'), sorted_cans[0][1])

    def recalcularopnum(self, opcans):
        self.firstopnum = 0
        self.secondopnum = 0
        for op in opcans:
            fr = SequenceMatcher(None, op.sentence, unicode(self.firstop, "utf-8")).ratio()
            sr = SequenceMatcher(None, op.sentence, unicode(self.secondop, "utf-8")).ratio()
            if fr > sr:
                self.firstopnum += 1
            else:
                self.secondopnum += 1

    def similarity(self, a, b):
        similarp = SequenceMatcher(None, a, b).ratio()

        if similarp > 0.58:
            return True
        return False
