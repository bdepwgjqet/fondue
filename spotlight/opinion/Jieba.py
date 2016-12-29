#!/usr/bin/env python
# -*- coding: utf-8 -*-

import jieba.posseg as pseg


class JiebaInvoker(object):

    def __init__(self, sentense):
        self.sentense = sentense

    def cut(self):
        return pseg.cut(self.sentense)
