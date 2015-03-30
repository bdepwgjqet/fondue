#!/usr/bin/python

class Solution:
    # @return a string
    def longestPalindrome(self, s):
        maxp = 0
        ret = ""
        for i in range(len(s)):
            r = min(i,len(s)-1-i)
            u = 0
            for j in range(r):
                if s[i-j-1] != s[i+j+1]:
                    u = j
                    break
                if j == r-1:
                    u = j+1
            if maxp < 2*u+1:
                maxp = 2*u+1
                ret = s[i-u:i+u+1]
            r = min(i+1,len(s)-i-1)
            u = 0
            for j in range(r):
                if s[i-j]!=s[i+j+1]:
                    u = j
                    break
                if j == r-1:
                    u = r
            if maxp < 2*u:
                maxp = 2*u
                ret = s[i-u+1:i+u+1]
        return ret

        
if __name__=='__main__':
    s = Solution()
    print s.longestPalindrome("abcdeffeddsakf")
