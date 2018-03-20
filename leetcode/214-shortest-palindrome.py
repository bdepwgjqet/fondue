#!/usr/bin/env python
# -*- coding: utf-8 -*-


class Solution:
    fail = None

    def kmp(self, s):
        for idx, c in enumerate(s):
            cur = idx - 1
            cur_fail = -1
            while True:
                if cur < 0:
                    break
                pre = self.fail[cur]
                if s[pre+1] == s[idx]:
                    cur_fail = pre + 1
                    break
                cur = pre
            self.fail[idx] = cur_fail

    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        self.fail = [-1 for x in range(len(s))]
        self.kmp(s)
        t = s[::-1]
        match_idx = 0
        for idx, c in enumerate(t):
            if s[match_idx] == c:
                match_idx = match_idx + 1
            else:
                while True:
                    if match_idx == 0:
                        break
                    match_idx = self.fail[match_idx-1] + 1
                    if s[match_idx] == c:
                        match_idx = match_idx + 1
                        break
        s_arr = [c for c in s]
        lack_arr = s_arr[match_idx:]
        res_arr = lack_arr[::-1]
        res_arr = res_arr + s_arr
        return "".join(res_arr)

solution = Solution()
print(solution.shortestPalindrome("aacecaaa"))
print(solution.shortestPalindrome("abcd"))
