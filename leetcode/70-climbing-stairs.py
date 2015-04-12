#!/usr/bin/python

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        dp = []
        dp.append(1)
        dp.append(1)
        for i in range(2,n+1):
            dp.append(dp[i-1]+dp[i-2])
        return dp[n]
        
if __name__=='__main__':
    s = Solution()
    print s.climbStairs(5)
