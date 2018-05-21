#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    dp = []
    sa = None
    sb = None
    sc = None

    def dfs(self, ia, ib):
        if self.dp[ia][ib] is not None:
            return self.dp[ia][ib]
        if ia + ib == len(self.sc):
            self.dp[ia][ib] = True
            return self.dp[ia][ib]
        find = False
        if ia < len(self.sa) and self.sa[ia] == self.sc[ia+ib]:
            find = find or self.dfs(ia+1, ib)
        if ib < len(self.sb) and self.sb[ib] == self.sc[ia+ib]:
            find = find or self.dfs(ia, ib+1)
        self.dp[ia][ib] = find
        return self.dp[ia][ib]

    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        n1 = len(s1) + 1
        n2 = len(s2) + 1
        if len(s3) != len(s1) + len(s2):
            return False
        self.dp = [[None for x in range(n2)] for y in range(n1)]
        self.sa = s1
        self.sb = s2
        self.sc = s3
        return self.dfs(0, 0)

solution = Solution()
print(solution.isInterleave('aabcc', 'dbbca', 'aadbbcbcac'))
print(solution.isInterleave('aabcc', 'dbbca', 'aadbbbaccc'))
