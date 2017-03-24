#!/usr/bin/env python
# -*- coding: utf-8 -*-

from Jieba import JiebaInvoker
from sklearn import feature_extraction
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer 

import operator
import pickle

def Cutword(infile):
    corpus = []
    for line in open(infile):
        if not line:
            continue
        review = line.strip()
        jbinvoker = JiebaInvoker(review)
        pars = jbinvoker.cut()
        corpus.append(" ".join([u for u,v in pars]))
    return corpus

def TrainBase(infile, cutwordfile, vectorfile):
# cut word
    corpus = Cutword(infile)

# save cut word res of corpus
    with open(cutwordfile, "w+") as f:
        for review in corpus:
            f.write(review + "\n")
        f.close()


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
            wordweight[words[j]] = weight[i][j]
        sorted_weight = sorted(wordweight.items(), key=operator.itemgetter(1), reverse=True)
        ctfidf.append(sorted_weight)
    return ctfidf


vectorfile = "trained-vec.pkl"
TrainBase("reviews.in", "reviews-cut-word.out", vectorfile)

#newcorpus = Cutword("newreviews.in")
#ckeys = Predict(newcorpus, vectorfile)

#with open("reviews-tf-idf.out", "w+") as f:
#    for keys in ckeys:
#        f.write('--------------------\n')
#        for k,v in keys:
#            f.write(k.encode('utf-8') + "\t" + str(v) + "\n")
