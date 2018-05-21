#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        target_num = {}
        target_c = 0
        find_num = {}
        for tc in t:
            if tc not in target_num:
                target_c = target_c + 1
                target_num[tc] = 0
                find_num[tc] = 0
            target_num[tc] = target_num[tc] + 1
        l = 0
        r = 0
        min_l = None
        res_seg = ""
        total_num = 0
        while r < len(s):
            cur_c = s[r]
            if cur_c in target_num:
                find_num[cur_c] = find_num[cur_c] + 1
                if find_num[cur_c] == target_num[cur_c]:
                    total_num = total_num + 1
                while True:
                    l_c = s[l]
                    if l_c in find_num:
                        if find_num[l_c] > target_num[l_c]:
                            find_num[l_c] = find_num[l_c] - 1
                        else:
                            break
                    l = l + 1
                if total_num == target_c:
                    if not min_l or min_l > r - l + 1:
                        min_l = r - l + 1
                        res_seg = s[l:r+1]
            else:
                pass
            r = r + 1
        return res_seg


solution = Solution()
print(solution.minWindow("ADOBECODEBANC", "ABC"))
print(solution.minWindow("aaaaaaaaaaaabbbbbcdd", "abcdd"))


