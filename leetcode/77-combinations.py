#!/usr/bin/python

class Solution:

    def dfs(self,nc,nv,nl):
        if nc == self.k:
            self.ans.append(nl[:])
            return
        if nv > self.n:
            return
        for i in range(nv,self.n+1):
            nl.append(i)
            self.dfs(nc+1,i+1,nl)
            nl.pop()

    # @return a list of lists of integers
    def combine(self, n, k):
        self.ans = []
        self.n = n
        self.k = k
        self.dfs(0,1,[])
        return self.ans

if __name__=='__main__':
    s = Solution()
    print s.combine(4,2)
