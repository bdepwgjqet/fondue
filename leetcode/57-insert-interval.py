#!/usr/bin/python

import heapq

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        ans = []
        l,r = newInterval.start,newInterval.end
        pin = False
        for i in range(len(intervals)):
            iv = intervals[i]
            if iv.end < iv.start:
                continue
            if iv.end < l:
                ans.append(iv)
            elif iv.start > r:
                if not pin:
                    ans.append(Interval(l,r))
                    pin = True
                ans.append(iv)
            else:
                l = min(l,iv.start)
                r = max(r,iv.end)
        if not pin:
            ans.append(Interval(l,r))
        return ans


if __name__=='__main__':
    s = Solution()
    #print s.merge([[1,3],[2,6],[8,10],[15,18]])
    ans = s.insert([Interval(1,3),Interval(6,9)],Interval(2,5))
    for i in ans:
        print i.start,i.end
