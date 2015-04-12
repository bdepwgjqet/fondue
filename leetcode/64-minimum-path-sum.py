#!/usr/bin/python

class Solution:

    def canGo(self,x,y):
        if x < 0 or x >= self.m:
            return False
        if y < 0 or y >= self.n:
            return False
        return True

    def dfs(self,x,y):
        if x == self.m - 1 and y == self.n - 1:
            self.dp[x][y] = self.mat[x][y]
        if self.dp[x][y] is not None:
            return self.dp[x][y]
        self.dp[x][y] = 1000000000
        if self.canGo(x+1,y):
            self.dp[x][y] = min(self.dfs(x+1,y)+self.mat[x][y],self.dp[x][y])
        if self.canGo(x,y+1):
            self.dp[x][y] = min(self.dfs(x,y+1)+self.mat[x][y],self.dp[x][y])
        return self.dp[x][y]

    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        self.mat = grid
        if len(self.mat) == 0:
            return 0
        self.m = len(self.mat)
        self.n = len(self.mat[0])
        self.dp = []
        for i in range(self.m):
            self.dp.append([])
            for j in range(self.n):
                self.dp[i].append(None)
        return self.dfs(0,0)
        
if __name__=='__main__':
    s = Solution()
    print s.minPathSum([
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ])
