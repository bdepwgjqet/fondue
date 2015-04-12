#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        l = 0
        r = len(A) - 1
        while l <= r:
            m = (l+r) >> 1
            if A[m] > target:
                r = m - 1
            else:
                l = m + 1
        if r < 0 or A[r] != target:
            return [-1,-1]
        rr = r

        l = 0
        r = len(A) - 1
        while l <= r:
            m = (l+r) >> 1
            if A[m] >= target:
                r = m - 1
            else:
                l = m + 1
        return [l,rr]
        
if __name__=='__main__':
    s = Solution()
    #print s.searchRange([5, 7, 7, 8, 8, 10],8)
    print s.searchRange([2,2],3)

