#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):
        p = 0
        while p < len(A)-1 and A[p+1]>=A[p]:
            p = p + 1
        p = p + 1
        if p >= len(A):
            p = 0
        B = []
        for i in range(p,len(A)):
            B.append(A[i])
        for i in range(p):
            B.append(A[i])
        (l,r) = (0,len(A)-1)
        while l <= r:
            m = (l+r) >> 1
            if B[m] > target:
                r = m - 1
            else:
                l = m + 1
        #print B,l,r,p
        if r < 0:
            return False
        if B[r] != target:
            return False
        return True
        
if __name__=='__main__':
    s = Solution()
    print s.search([1],0)
    print s.search([4,5,6,7,0,1,2],0)
    print s.search([1],2)
    print s.search([1,3],3)
    print s.search([3,1],3)
    print s.search([3,5,1],3)

