#!/usr/bin/env python
# -*- coding: utf-8 -*-

from sklearn import feature_extraction
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer

import operator
import pickle
import sys, traceback
import re


def LoadSentence(cfile):
    corpus = []
    with open(cfile, "r", encoding="utf8") as f:
        for line in f:
            if not line:
                continue
            corpus.append(line.strip())
    return corpus

def TrainBase(corpusfile, vectorfile):
# Train vector file 
    corpus = LoadSentence(corpusfile)

    vectorizer = CountVectorizer()

    vec_train = vectorizer.fit_transform(corpus)
    pickle.dump(vectorizer.vocabulary_, open(vectorfile, "wb"))

def Predict(contents, vecfile):
    transformer = TfidfTransformer()
    trained_vec = CountVectorizer(vocabulary=pickle.load(open(vecfile, "rb")))
    tfidf = transformer.fit_transform(trained_vec.fit_transform(contents))

    words = trained_vec.get_feature_names()
    weight = tfidf.toarray()

    ctfidf = []
    for i in range(len(weight)):
        wordweight = dict()
        for j in range(len(words)):
            if weight[i][j] > 0:
                wordweight[words[j]] = weight[i][j]
        sorted_weight = sorted(wordweight.items(), key=operator.itemgetter(1), reverse=True)
        ctfidf.append(sorted_weight)
    return ctfidf

def TfIdf(docfile):
    docs = LoadSentence(docfile)
    vectorizer = CountVectorizer()
    transformer = TfidfTransformer()
    vec = vectorizer.fit_transform(docs)
    tfidf = transformer.fit_transform(vec)
    words = vectorizer.get_feature_names()
    weight = tfidf.toarray()

    ctfidf = []
    for i in range(len(weight)):
        wordweight = dict()
        for j in range(len(words)):
            if weight[i][j] > 0:
                wordweight[words[j]] = weight[i][j]
        sorted_weight = sorted(wordweight.items(), key=operator.itemgetter(1), reverse=True)
        ctfidf.append(sorted_weight)
    return ctfidf


def test():
    vectorfile = "trained-vec.pkl"
    TrainBase("corpus.in", vectorfile)

    newcorpus = LoadSentence("test.in")
    ckeys = Predict(newcorpus, vectorfile)

    with open("test.out", "w+", encoding="utf8") as f:
        for keys in ckeys:
            f.write('--------------------\n')
            for k,v in keys:
                f.write(k + "\t" + str(v) + "\n")

def process():
    #test()

    print("Args number: " + str(len(sys.argv)))

    pars = {}
    for arg in sys.argv:
        pair = (re.split('=|:', arg))
        if len(pair) > 1:
            pars[pair[0].lstrip('/')] = pair[1]

    corpusfile = pars["CorpusFile"]
    predictfile = pars["PredictFile"]
    runtype = pars["RunType"]
    trainedvec = pars["TrainedVec"]
    trainingvec = pars["TrainingVec"]
    opath = pars["WordsScore"]

    if "train" in runtype:
        ofile = open(opath, 'w+', encoding="utf8")
        TrainBase(corpusfile, trainingvec)
        ofile.write("Success trained vec!")
    elif "predict" in runtype:
        ofile = open(opath, 'w+', encoding="utf8")
        ovec = open(trainingvec, "w+", encoding="utf8")
        predictcons = LoadSentence(predictfile)
        wweight = Predict(predictcons, trainedvec)
        idx = 0
        for wdic in wweight:
            for k,v in wdic:
                ofile.write(str(idx) + "\t" + k + "\t" + str(v) + "\n")
            idx = idx + 1
        ovec.write("Predict words score successed!")
    elif "realtime" in runtype:
        ofile = open(opath, 'w+', encoding="utf8")
        ovec = open(trainingvec, "w+", encoding="utf8")
        wweight = TfIdf(predictfile)

        idx = 0
        for wdic in wweight:
            for k,v in wdic:
                ofile.write(str(idx) + "\t" + k + "\t" + str(v) + "\n")
            idx = idx + 1
        ovec.write("Predict words score successed!")
    else:
        print("Error runtype: " + runtype)


if __name__=='__main__':
    try:
        process()
    except:
        traceback.print_exc(file=sys.stdout)
        sys.exit(0)
