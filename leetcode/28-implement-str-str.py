#!/usr/bin/python

class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return an integer
    def strStr(self, haystack, needle):
        return haystack.find(needle)

if __name__=='__main__':
    s = Solution()
    print s.strStr("hack acm","acm")

