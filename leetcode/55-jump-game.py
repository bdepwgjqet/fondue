#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def canJump(self, A):
        p = 0
        c = 0
        while p < len(A) - 1:
            mto = p + A[p]
            np = p
            nmto = mto
            for j in range(p,mto+1):
                if j >= len(A) - 1:
                    return True
                if j+A[j] > nmto:
                    nmto = j+A[j]
                    np = j
            if np <= p:
                break
            p = np
            c = c + 1
        return p >= len(A) - 1

if __name__=='__main__':
    s = Solution()
    print s.canJump([2,3,1,1,4])
