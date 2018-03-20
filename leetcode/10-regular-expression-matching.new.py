#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    dp = None
    def dfs(self, si, pi, s, p):
        if self.dp[si][pi] is not None:
            return self.dp[si][pi]
        if pi == len(p) and si == len(s):
            self.dp[si][pi] = True
            return self.dp[si][pi]
        if pi == len(p):
            self.dp[si][pi] = False
            return self.dp[si][pi]


        is_match = False
        if pi+1 < len(p) and p[pi+1] == '*':
            is_match = is_match or self.dfs(si, pi+2, s, p)
        if not is_match and si < len(s):
            if s[si] == p[pi] or p[pi] == '.':
                if pi+1 < len(p) and p[pi+1] == '*':
                    is_match = is_match or self.dfs(si+1, pi, s, p)
                else:
                    is_match = is_match or self.dfs(si+1, pi+1, s, p)
            else:
                pass
        self.dp[si][pi] = is_match
        return self.dp[si][pi]
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = len(s) + 1
        n = len(p) + 1
        self.dp = [[None for x in range(n)] for y in range(m)]
        is_match = self.dfs(0, 0, s, p)
        return is_match

solution = Solution()
print(solution.isMatch("aa", "a"))
print(solution.isMatch("aa", "aa"))
print(solution.isMatch("aaa", "aa"))
print(solution.isMatch("aaa", "a*"))
print(solution.isMatch("aaa", ".*"))
print(solution.isMatch("aab", "c*a*b"))
print(solution.isMatch("aab", ".*c"))
