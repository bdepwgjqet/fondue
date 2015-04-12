#!/usr/bin/python

class Solution:
    def canGo(self,x,y):
        if x < 0 or x >= self.n:
            return False
        if y < 0 or y >= self.n:
            return False
        if self.vis[x][y] != 0:
            return False
        return True

    # @return a list of lists of integer
    def generateMatrix(self, n):
        if n == 0:
            return []
        self.n = n
        self.vis = []
        for i in range(n):
            self.vis.append([])
            for j in range(n):
                self.vis[i].append(0)
        self.vis[0][0] = 1
        c = 2
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
            self.vis[nx][ny] = c 
            c = c + 1
        return self.vis

if __name__=='__main__':
    s = Solution()
    ans = s.generateMatrix(5)
    for i in ans:
        print i
