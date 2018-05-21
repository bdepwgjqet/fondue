#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def maxSlidingWindow(self, nums, k):
        st = []
        res = []
        for idx, x in enumerate(nums):
            while len(st) > 0:
                h, hi = st[0]
                if idx - hi >= k:
                    st.pop(0)
                else:
                    break
            while len(st) > 0:
                h, hi = st[-1]
                if h <= x:
                    st.pop()
                else:
                    break
            st.append((x, idx))
            if idx >= k-1:
                c_h, c_i = st[0]
                res.append(c_h)
        return res

s = Solution()
print(s.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))
