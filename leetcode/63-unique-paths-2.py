#!/usr/bin/python

class Solution:

    def canGo(self,x,y):
        if x < 0 or x >= self.m:
            return False
        if y < 0 or y >= self.n:
            return False
        if self.mat[x][y] == 1:
            return False
        return True

    def dfs(self,x,y):
        if self.dp[x][y] is not None:
            return self.dp[x][y]
        if x == self.m - 1 and y == self.n - 1:
            self.dp[x][y] = 1
            return 1
        self.dp[x][y] = 0
        if self.canGo(x+1,y):
            self.dp[x][y] += self.dfs(x+1,y)
        if self.canGo(x,y+1):
            self.dp[x][y] += self.dfs(x,y+1)
        return self.dp[x][y]

    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        self.mat = obstacleGrid
        if len(self.mat) == 0 or self.mat[0][0] == 1:
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
    print s.uniquePathsWithObstacles([
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ])
