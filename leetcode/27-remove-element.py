#!/usr/bin/python

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        ans = 0
        for i in xrange(len(A)):
            if A[i] != elem:
                A[ans] = A[i]
                ans = ans + 1
        return ans

if __name__=='__main__':
    s = Solution()
    print s.removeElement([1,1,2],1)
