#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        p = 0
        c = 0
        while p < len(A) - 1:
            mto = p + A[p]
            np = p
            nmto = mto
            for j in range(p,mto+1):
                if j >= len(A) - 1:
                    return c + 1
                if j+A[j] > nmto:
                    nmto = j+A[j]
                    np = j
            p = np
            c = c + 1
        return c

if __name__=='__main__':
    s = Solution()
    print s.jump([2,3,1,1,4])
