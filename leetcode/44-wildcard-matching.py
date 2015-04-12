#!/usr/bin/python

class Solution:

    # @param s, an input string
    # @param p, a pattern string
    # @return a boolean
    def isMatch(self, s, p):
        sa = pa = 0
        sb = pb = 0
        hasx = False
        while sa < len(s):
            if pa == len(p):
                if hasx:
                    sb = sb + 1
                    sa = sb
                    pa = pb
                else:
                    return False
            elif p[pa] == '?':
                pa = pa + 1
                sa = sa + 1
                continue
            elif p[pa] == '*':
                hasx = True
                sb = sa
                while pa < len(p) and p[pa] == '*':
                    pa = pa + 1
                if pa == len(p):
                    return True
                pb = pa
            else:
                if p[pa] != s[sa]:
                    if hasx == False:
                        return False
                    sb = sb + 1
                    sa = sb
                    pa = pb
                else:
                    sa = sa + 1
                    pa = pa + 1
        while pa < len(p) and p[pa] == '*':
            pa = pa + 1
        return pa >= len(p)

if __name__=='__main__':
    s = Solution()
    print s.isMatch("aa","a?") 
    print s.isMatch("abefcdgiescdfimde", "ab*cd?i*de")


