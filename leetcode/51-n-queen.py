#!/usr/bin/python

class Solution:
    def canPlace(self,b,i):
        for k in range(len(b)):
            if b[k][i] == 'Q':
                return False
        j = len(b) - 1
        u = 1
        while j>=0:
            if i-u >= 0 and b[j][i-u] == 'Q':
                return False
            if i+u < self.n and b[j][i+u] == 'Q':
                return False
            j = j - 1
            u = u + 1
        return True

    def dfs(self,r,b):
        if r == self.n:
            self.ans.append(b[:])
            return
        for i in range(self.n):
            if self.canPlace(b,i):
                now = '.'*i+'Q'+'.'*(self.n-i-1)
                b.append(now)
                self.dfs(r+1,b)
                b.pop()

    # @return a list of lists of string
    def solveNQueens(self, n):
        self.n = n
        self.ans = []
        self.dfs(0,[])
        return self.ans

if __name__=='__main__':
    s = Solution()
    print s.solveNQueens(4)
