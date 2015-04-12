#!/usr/bin/python

class Solution:
    def dfs(self,p,cl,ci):
        if p == len(self.num):
            if cl not in self.ans:
                self.ans.append(cl[:])
            return
        for i in range(len(self.num)):
            if i not in ci:
                ci.append(i)
                cl.append(self.num[i])
                self.dfs(p+1,cl,ci)
                cl.pop()
                ci.pop()

    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        self.num = num
        self.ans = []
        self.dfs(0,[],[])
        return self.ans
        
if __name__=='__main__':
    s = Solution()
    print s.permute([2,3,1,1,4])
    print s.permute([2,3,1])
    print s.permute([1,3,1])
