#!/usr/bin/python

class Solution:

    # @param matrix, a list of lists of integers
    # @return nothing (void), do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        n = len(matrix)
        for i in range(n/2):
            for j in range(i,n-1-i):
                matrix[i][j],matrix[j][n-1-i],matrix[n-1-i][n-1-j],matrix[n-1-j][i] = matrix[n-1-j][i],matrix[i][j],matrix[j][n-1-i],matrix[n-1-i][n-1-j]
        return matrix
        
if __name__=='__main__':
    s = Solution()
    print s.rotate([[1,2],[3,4]])
