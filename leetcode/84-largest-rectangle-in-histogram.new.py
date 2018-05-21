#!/usr/bin/env python
# -*- coding: utf-8 -*-


class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        st = []
        st.append((-1, -1, 0))
        max_area = 0
        for idx, h in enumerate(heights):
            righti, righth, rightv = st[-1]
            while len(st) > 0:
                prei, preh, prev = st[-1]
                if preh >= h:
                    max_area = max(
                        max_area, (righti - prei)*preh + prev)
                    st.pop()
                else:
                    break
            prei, preh, prev = st[-1]
            max_area = max(max_area, (idx - prei) * h)
            left_v = (idx - prei) * h
            st.append((idx, h, left_v))

        righti, righth, rightv = st[-1]
        while len(st)>0:
            i, h, v = st[-1]
            max_area = max(max_area, (righti - i)*h + v)
            st.pop()
        return max_area


solution = Solution()
print(solution.largestRectangleArea([2, 1, 5, 6, 2, 3]))
print(solution.largestRectangleArea([2, 3]))
