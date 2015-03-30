#!/usr/bin/python

class Solution:

    def gao(self,x):
        if x == 0:
            return (0,1)
        u,v = self.gao(x/10)
        return (x%10*v+u,v*10)

    # @return an integer
    def reverse(self, x):
        flag = 1
        if x < 0:
            flag = -1
            x = -x
        u,v = self.gao(x)
        if u >= 2147483648:
            u = 0
        return flag*u
        

if __name__=='__main__':
    s = Solution()
    print s.reverse(123)
    print s.reverse(1534236469)
    print s.reverse(1000000003)

