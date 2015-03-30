#!/usr/bin/python

class Solution:

    def gao(self,A,B,ind):
        if len(A)==0:
            return 1.0*B[ind-1]
        if len(B)==0:
            return 1.0*A[ind-1]
        mi = max(ind/2-1,0)
        mi = min(mi,len(A)-1)
        mi = min(mi,len(B)-1)
        a = A[mi]
        b = B[mi]
        if a > b:
            return self.gao(B,A,ind)
        if ind <= 1:
            return 1.0*a
        return self.gao(A[mi+1:],B,ind-mi-1)

    def findMedianSortedArrays(self, A, B):
        m = len(A)
        n = len(B)
        if (m+n)&1 > 0:
            return self.gao(A,B,(m+n+1)/2)
        else:
            return (self.gao(A,B,(m+n)/2)+self.gao(A,B,(m+n+2)/2))/2

if __name__=='__main__':
    s = Solution()
    print s.findMedianSortedArrays(A=[1],B=[2,3,4,5,6])
