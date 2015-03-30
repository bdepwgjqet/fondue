#!/usr/bin/python

class Solution:
    def isIt(self,strs,i):
        c = strs[0][i]
        for j in range(len(strs)):
            if len(strs[j]) <= i or strs[j][i] != c:
                return False
        return True
    # @return a string
    def longestCommonPrefix(self, strs):
        if len(strs) <= 0:
            return ""
        ex = strs[0]
        i = 0
        while i < len(ex):
            if self.isIt(strs,i) == False:
                break
            i = i + 1
        return ex[0:i]
        
if __name__=='__main__':
    s = Solution()
    print s.longestCommonPrefix(["XCX","X"])
