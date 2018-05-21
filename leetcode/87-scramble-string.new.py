#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    dp = []
    sa = None
    sb = None
    def dfs(self, ia, ib, l):
        if self.dp[ia][ib][l] is not None:
            return self.dp[ia][ib][l]
        if l == 0:
            self.dp[ia][ib][l] = True
            return self.dp[ia][ib][l]
        if l == 1:
            self.dp[ia][ib][l] = (self.sa[ia] == self.sb[ib])
            return self.dp[ia][ib][l]
        res = False
        for idx in range(1, l):
            if self.dfs(ia, ib, idx) and self.dfs(ia+idx, ib+idx, l-idx):
                res = True
                break
            if self.dfs(ia, ib+l-idx, idx) and self.dfs(ia+idx, ib, l-idx):
                res = True
                break
        self.dp[ia][ib][l] = res
        return self.dp[ia][ib][l]

    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        n = len(s1) + 1
        self.dp = [[[None for x in range(n)] for y in range(n)] for z in range(n)]
        self.sa = s1
        self.sb = s2
        return self.dfs(0, 0, len(s1))
        

solution = Solution()
print(solution.isScramble("rgtae", "great"))
print(solution.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb"))
