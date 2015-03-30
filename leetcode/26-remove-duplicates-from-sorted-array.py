#!/usr/bin/python

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if not A: return 0
        pre = 0
        for i in range(len(A)):
            if A[i] != A[pre]:
                A[pre+1] = A[i]
                pre = pre + 1
        return pre + 1
        
if __name__=='__main__':
    s = Solution()
    print s.removeDuplicates([1,1,2])
