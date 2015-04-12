#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of integers
    # @return nothing (void), do not return anything, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        xs = set([])
        ys = set([])
        xn = len(matrix)
        yn = len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    xs.add(i)
                    ys.add(j)
        for i in xs:
            for j in range(yn):
                matrix[i][j] = 0
        for i in ys:
            for j in range(xn):
                matrix[j][i] = 0
        return matrix

if __name__=='__main__':
    s = Solution()
    print s.setZeroes([[0,1],[1,0]])
    print s.setZeroes([[0],[1]])
