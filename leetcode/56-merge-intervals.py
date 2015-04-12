#!/usr/bin/python

import heapq

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        h = []
        ans = []
        for seg in intervals:
            heapq.heappush(h,(seg.start,seg.end))
        while len(h) > 0:
            (l,r) = heapq.heappop(h)
            if l>r:
                continue
            while len(h) > 0:
                (x,y) = heapq.heappop(h)
                if x > r:
                    heapq.heappush(h,(x,y))
                    break
                else:
                    r = max(y,r)
            ans.append(Interval(l,r))
            print l,r
        return ans

if __name__=='__main__':
    s = Solution()
    #print s.merge([[1,3],[2,6],[8,10],[15,18]])
    print s.merge([Interval(1,4),Interval(2,3)])
