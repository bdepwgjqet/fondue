#!/usr/bin/python

class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        MAX_INT = 2147483647 
        if divisor == 0:
            return MAX_INT
        ans = 0
        k = 1
        flag = 1
        if dividend < 0:
            flag = -flag
            dividend = -dividend
        if divisor < 0:
            flag = -flag
            divisor = -divisor

        while dividend >= divisor:
            now = divisor
            c = 1
            while dividend >= now+now:
                now = now + now
                c = c + c
            dividend -= now
            ans += c

        if flag > 0 and ans > MAX_INT:
            ans = MAX_INT
        if flag < 0 and ans > MAX_INT+1:
            ans = MAX_INT+1

        if flag > 0:
            return ans
        return -ans

if __name__=='__main__':
    s = Solution()
    print s.divide(0,1)

