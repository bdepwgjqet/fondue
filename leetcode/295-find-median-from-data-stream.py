#!/usr/bin/env python
# -*- coding: utf-8 -*-

import heapq

class MedianFinder:
    def __init__(self):
        self.small_heap = []
        self.big_heap = []
    def addNum(self, num):
        if len(self.small_heap) == 0 or num >= self.small_heap[0]:
            heapq.heappush(self.small_heap, num)
        else:
            heapq.heappush(self.big_heap, -num)
        if len(self.big_heap) - len(self.small_heap) > 1:
            x = -heapq.heappop(self.big_heap)
            heapq.heappush(self.small_heap, x)
        if len(self.small_heap) - len(self.big_heap) > 1:
            x = heapq.heappop(self.small_heap)
            heapq.heappush(self.big_heap, -x)
            
    def findMedian(self):
        if len(self.small_heap) == len(self.big_heap):
            return (self.small_heap[0] - self.big_heap[0]) / 2
        if len(self.small_heap) > len(self.big_heap):
            return self.small_heap[0]
        return -self.big_heap[0]

s = MedianFinder()
s.addNum(-1)
print(s.findMedian())
s.addNum(-2)
print(s.findMedian())
s.addNum(-3)
print(s.findMedian())
s.addNum(-4)
print(s.findMedian())
s.addNum(-5)
print(s.findMedian())
