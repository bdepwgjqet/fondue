#!/usr/bin/python

class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isOk(self,l):
        st = set([])
        for i in range(len(l)):
            if l[i] == '.':
                continue
            if l[i] in st:
                return False
            st.add(l[i])
        return True

    def isValidSudoku(self, board):
        for i in range(len(board)):
            if self.isOk(board[i]) == False:
                return False
            v = []
            for j in range(len(board)):
                v.append(board[j][i])
            if self.isOk(v) == False:
                return False
            v = []
            for j in range(len(board)):
                s = i/3*3+j/3
                t = i%3*3+j%3
                v.append(board[s][t])
            if self.isOk(v) == False:
                return False
        return True
         
if __name__=='__main__':
    s = Solution()
    print s.isValidSudoku([['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.'],['1','.','3','5','6','.','.','.','.']])
