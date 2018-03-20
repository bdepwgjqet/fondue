#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = []
        cur = 0
        digit = False
        for idx, c in enumerate(s):
            if c == ' ':
                continue
            if c in '(+-':
                if digit:
                    st.append(cur)
                    digit = False
                st.append(c)
                cur = 0
            elif c == ')':
                if digit:
                    st.append(cur)
                    digit = False
                cur_sum = 0
                flag = 1
                while st[-1] != '(':
                    if st[-2] == '(':
                        cur_sum = cur_sum + st[-1]
                        st.pop()
                        break
                    if st[-2] == '-':
                        flag = -1
                    else:
                        flag = 1
                    cur_sum = cur_sum + flag * st[-1]
                    st.pop()
                    st.pop()
                st.pop()
                st.append(cur_sum)
            else:
                cur = cur * 10
                cur = cur + ord(c) - ord('0')
                digit = True
        if digit:
            st.append(cur)
        cur_sum = 0
        flag = 1
        for e in st:
            if e == '-':
                flag = -1
            elif e == '+':
                flag = 1
            else:
                cur_sum = cur_sum + flag * e
        return cur_sum

solution = Solution()
print(solution.calculate("(1+(4+5+2)-3)+(6+8)"))
print(solution.calculate("1+1"))
print(solution.calculate("2-1+2"))
print(solution.calculate("2-(5-6)"))


