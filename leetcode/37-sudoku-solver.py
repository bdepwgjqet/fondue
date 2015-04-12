#!/usr/bin/python

class Solution:

    def dfs(self,board,i,j):
        if self.find:
            return
        if i >= len(board):
            self.find = True
            return
        k = i/3*3 + j/3
        ni = i if j + 1 < len(board) else i + 1
        nj = j + 1 if j + 1 < len(board) else 0
        if board[i][j] != '.':
            self.dfs(board,ni,nj)
        else:
            for v in range(len(board)):
                c = str(v+1)
                if c in self.ast[i] or c in self.bst[j] or c in self.cst[k]:
                    continue
                #print i,j,v,self.ast[i], self.bst[j], self.cst[k]
                self.ast[i].add(c)
                self.bst[j].add(c)
                self.cst[k].add(c)
                board[i][j] = c
                self.dfs(board,ni,nj)
                if self.find:
                    return
                board[i][j] = '.'
                self.ast[i].remove(c)
                self.bst[j].remove(c)
                self.cst[k].remove(c)

    # @param board, a 9x9 2D array
    # Solve the Sudoku by modifying the input board in-place.
    # Do not return any value.
    def solveSudoku(self, board):
        self.find = False 
        self.ast = []
        self.bst = []
        self.cst = []
        for i in range(len(board)):
            self.ast.append(set())
            self.bst.append(set())
            self.cst.append(set())
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] != '.':
                    self.ast[i].add(board[i][j])
                    self.bst[j].add(board[i][j])
                    self.cst[i/3*3+j/3].add(board[i][j])
        self.dfs(board,0,0)
        print board

if __name__=='__main__':
    s = Solution()
    board = [['5','3','.','.','7','.','.','.','.'],
             ['6','.','.','1','9','5','.','.','.'],
             ['.','9','8','.','.','.','.','6','.'],
             ['8','.','.','.','6','.','.','.','3'],
             ['4','.','.','8','.','3','.','.','1'],
             ['7','.','.','.','2','.','.','.','6'],
             ['.','6','.','.','.','.','2','8','.'],
             ['.','.','.','4','1','9','.','.','5'],
             ['.','.','.','.','8','.','.','7','9'],
            ]
    print s.solveSudoku(board)
