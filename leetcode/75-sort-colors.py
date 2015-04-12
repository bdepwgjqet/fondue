#!/usr/bin/python

class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        r  = len(A) - 1
        l = 0
        i = 0
        while i <= r or l <= r:
            if i > r:
                A[l] = 1
                l = l + 1
                continue
            if A[i] == 0:
                A[l] = A[i]
                l = l + 1
                i = i + 1
            elif A[i] == 2:
                A[i],A[r] = A[r],A[i]
                r = r - 1
            else:
                i = i + 1
        return A
        
if __name__=='__main__':
    s = Solution()
    print s.sortColors([0,1,2,2,1,0])
