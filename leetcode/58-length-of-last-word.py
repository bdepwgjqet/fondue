#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        return len(s.rstrip().split(" ").pop())

if __name__=='__main__':
    s = Solution()
    print s.lengthOfLastWord("hello world ")
