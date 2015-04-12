#!/usr/bin/python

class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n < 0:
            return 1.0/self.pow(x,-n)
        ans = 1.0
        while n > 0:
            if n&1 > 0:
                ans = ans*x
            n>>=1
            x = x*x
        return ans

if __name__=='__main__':
    s = Solution()
    print s.pow(3.1,9)
