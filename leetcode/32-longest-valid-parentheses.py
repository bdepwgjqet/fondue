#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        st = []
        ans = 0
        pre = -1
        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
            else:
                if len(st) == 0:
                    pre = i
                else:
                    st.pop()
                    val = i-pre if len(st) == 0 else i-st[-1]
                    ans = max(ans,val)
        return ans

if __name__=='__main__':
    s = Solution()
    s.longestValidParentheses(")()())")

