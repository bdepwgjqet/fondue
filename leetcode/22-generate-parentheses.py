#!/usr/bin/python

class Solution:
    # @param an integer
    # @return a list of string
    def dfs(self,n,c,tmp):
        if n == 0 and c == 0:
            self.ret.append(tmp)
            return
        if n == 0:
            self.dfs(n,c-1,tmp+")")
            return
        self.dfs(n-1,c+1,tmp+"(")
        if c > 0:
            self.dfs(n,c-1,tmp+")")

    def generateParenthesis(self, n):
        self.ret = []
        self.dfs(n,0,"")
        return self.ret

if __name__=='__main__':
    s = Solution()
    print s.generateParenthesis(3)
