#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        l = 0
        r = len(A) - 1
        while l <= r:
            m = (l+r)>>1
            if A[m] > target:
                r = m - 1
            else:
                l = m + 1
        if r < 0 or A[r] != target:
            return r+1
        return r
         
if __name__=='__main__':
    s = Solution()
    print s.searchInsert([1,3,5,6],2)

