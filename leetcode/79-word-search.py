#!/usr/bin/python

class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean

    def go(self,x,y):
        if x < 0 or x >= self.m: 
            return False
        if y < 0 or y >= self.n:
            return False
        if self.vis[x][y]:
            return False
        return True

    def dfs(self,now,u,v):
        if now == len(self.word):
            return True
        if self.board[u][v] != self.word[now]:
            return False
        if now == len(self.word) - 1:
            return True
        for i in range(len(self.d)):
            x = self.d[i][0] + u
            y = self.d[i][1] + v
            if self.go(x,y):
                self.vis[x][y] = True
                if self.dfs(now+1,x,y):
                    return True
                self.vis[x][y] = False
        return False

    def exist(self, board, word):
        if len(board) <= 0:
            return False
        self.board = board
        self.word = word
        self.m = len(board)
        self.n = len(board[0])
        self.d = [[1,0],[-1,0],[0,1],[0,-1]]
        self.vis = []
        for i in range(self.m):
            self.vis.append([])
            for j in range(self.n):
                self.vis[i].append(False)

        for i in range(self.m):
            for j in range(self.n):
                self.vis[i][j] = True
                if self.dfs(0,i,j):
                    return True
                self.vis[i][j] = False
        return False

if __name__=='__main__':
    s = Solution()
    #print s.exist(["aa"],"aa")
    #print s.exist(["ab","cd"],"acdb")
    print s.exist(["ABCE","SFES","ADEE"], "ABCESEEEFS")
