#!/usr/bin/python

class Solution:
    # @param x, an integer
    # @return an integer
    def mySqrt(self, x):
        l = 0
        r = x
        while l <= r:
            mid = (l+r) >> 1
            if mid*mid <= x:
                l = mid + 1
            else:
                r = mid - 1
        return r
        
if __name__=='__main__':
    s = Solution()
    print s.mySqrt(16)
    print s.mySqrt(0)
    print s.mySqrt(1)
    print s.mySqrt(18)
