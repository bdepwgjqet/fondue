#!/usr/bin/python

class Solution:
    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        A.sort()
        i = 0
        ans = 0
        while i < len(A):
            A[ans] = A[i]
            ans = ans + 1
            if i+1 < len(A) and A[i+1] == A[i]:
                A[ans] = A[i]
                ans = ans + 1
                i = i + 1
                while i < len(A) and A[i] == A[i-1]:
                    i = i + 1
                continue
            i = i + 1
        return ans
            

if __name__=='__main__':
    s = Solution()
    print s.removeDuplicates([1,2,3,1,2,3,1,2])
