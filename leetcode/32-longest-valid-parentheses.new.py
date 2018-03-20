#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = []
        st.append((-1, -1))
        max_valid = 0
        for idx, c in enumerate(s):
            if c == '(':
                st.append((1, idx))
            else:
                if len(st) <= 0:
                    continue
                ptype, pidx = st[-1]
                if ptype == 1:
                    st.pop()
                    tmp_type, mxidx = st[-1]
                    max_valid = max(max_valid, idx - mxidx)
                else:
                    st.append((-1, idx))
        return max_valid

solution = Solution()
print(solution.longestValidParentheses(')()())'))
