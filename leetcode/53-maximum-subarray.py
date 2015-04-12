#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        if len(A) == 0:
            return 0
        ans = A[0]
        val = 0
        for i in range(len(A)):
            val += A[i]
            ans = max(val,ans)
            if val < 0:
                val = 0
        return ans

if __name__=='__main__':
    s = Solution()
    print s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
