#!/usr/bin/python

class Solution:
    def canGo(self,x,y):
        if x < 0 or x >= self.m:
            return False
        if y < 0 or y >= self.n:
            return False
        if self.vis[x][y] != 0:
            return False
        return True

    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        if len(matrix) == 0:
            return []
        self.m = len(matrix)
        self.n = len(matrix[0])
        self.vis = []
        for i in range(self.m):
            self.vis.append([])
            for j in range(self.n):
                self.vis[i].append(0)
        ans = []
        ans.append(matrix[0][0])
        self.vis[0][0] = 1
        d = [[0,1],[1,0],[0,-1],[-1,0]]
        (nx,ny) = (0,0)
        dd = 0
        while True:
            (nnx,nny) = (nx+d[dd][0],ny+d[dd][1])
            if not self.canGo(nnx,nny):
                dd = (dd+1) % 4
                (nnx,nny) = (nx+d[dd][0],ny+d[dd][1]) 
            if not self.canGo(nnx,nny):
                break
            nx,ny = nnx,nny
            ans.append(matrix[nx][ny])
            self.vis[nx][ny] = 1
        return ans

if __name__=='__main__':
    s = Solution()
    print s.spiralOrder([
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ])
