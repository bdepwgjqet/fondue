#!/bin/bash

python3 tfidf.py CorpusFile:corpus.in PredictFile:predict.in RunType:$1 TrainedVec:trained-vec.pkl TrainingVec:training-vec.pkl WordsScore:predict.out > terminal.out
