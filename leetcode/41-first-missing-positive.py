#!/usr/bin/python

class Solution:

    def gao(self,A,i):
        if A[i] == i+1:
            return
        if A[i] <= 0:
            return
        if A[i] > len(A):
            return
        j = A[i] - 1
        if j > i:
            (A[i],A[j]) = (A[j],A[i])
            if A[i] != j+1:
                self.gao(A,i)
        else:
            A[j] = A[i]

    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        for i in range(len(A)):
            self.gao(A,i)
        for i in range(len(A)):
            if A[i] != i+1:
                return i+1
        return len(A)+1

        
if __name__=='__main__':
    s = Solution()
    print s.firstMissingPositive([3,4,-1,1])
