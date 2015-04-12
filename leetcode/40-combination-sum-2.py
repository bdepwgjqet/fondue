#!/usr/bin/python

import re

class Solution:

    def dfs(self,now,target,li):
        if target < 0:
            return
        if target == 0:
            self.ret.append(li[:])
            return
        if now >= len(self.num):
            return
        for i in range(now,len(self.num)):
            if i != now and self.num[i] == self.num[i-1]:
                continue
            if target >= self.num[i]:
                li.append(self.num[i])
                self.dfs(i+1,target-self.num[i],li)
                li.pop()

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        self.ret = []
        self.num = candidates
        self.num.sort()
        self.dfs(0,target,[])
        return self.ret

if __name__=='__main__':
    s = Solution()
    print s.combinationSum2([10,1,2,7,6,1,5],8)
    print s.combinationSum2([2,5,2,1,2],5)
    print s.combinationSum2([3,1,3,5,1,1],8)
