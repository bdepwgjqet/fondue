#!/usr/bin/python

class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        if m > n:
            return self.uniquePaths(n,m)
        ret = 1
        for i in range(m-1):
            ret *= m+n-2-i
            ret /= 1+i
        return ret

if __name__=='__main__':
    s = Solution()
    print s.uniquePaths(3,7)
