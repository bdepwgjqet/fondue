#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
        arr = []
        for i in matrix:
            for j in i:
                arr.append(j)
        l = 0
        r = len(arr) - 1
        while l <= r:
            mid = (l+r) >> 1
            if arr[mid] < target:
                l = mid + 1
            elif arr[mid] > target:
                r =  mid - 1
            else:
                return True
        return False

if __name__=='__main__':
    s = Solution()
    print s.searchMatrix([
        [1,   3,  5,  7],
        [10, 11, 16, 20],
        [23, 30, 34, 50]],3)
