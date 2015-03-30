#!/usr/bin/python

class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False
        if x == 0:
            return True
        d = 1
        t = x
        while t>0:
            t/=10
            d*=10
        d/=10
        t = x
        while t>0 and d>0:
            if t%10 != (t/d)%10:
                return False
            t/=10
            d/=100
        return True

if __name__=='__main__':
    s = Solution()
    print s.isPalindrome(129821)
    print s.isPalindrome(-2147447412)
