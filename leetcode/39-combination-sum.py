#!/usr/bin/python

import re

class Solution:

    def dfs(self,now,target,li):
        if target < 0:
            return
        if target == 0:
            self.ret.append(li[:])
            return
        for i in range(now,len(self.num)):
            if target >= self.num[i]:
                li.append(self.num[i])
                self.dfs(i,target-self.num[i],li)
                li.pop()

    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum(self, candidates, target):
        self.ret = []
        self.num = list(set(candidates))
        self.num.sort()
        self.dfs(0,target,[])
        return self.ret

if __name__=='__main__':
    s = Solution()
    print s.combinationSum([2,2,3],7)
