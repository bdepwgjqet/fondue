#!/usr/bin/python

class Solution:
    def dfs(self,p,cl,ci):
        if p == len(self.num):
            self.ans.append(cl[:])
            return
        for i in range(len(self.num)):
            if i not in ci:
                if i > 0 and i - 1 not in ci and self.num[i-1] == self.num[i]:
                    continue
                ci.append(i)
                cl.append(self.num[i])
                self.dfs(p+1,cl,ci)
                cl.pop()
                ci.pop()

    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        self.num = num
        self.num.sort()
        self.ans = []
        self.dfs(0,[],[])
        return self.ans
        
if __name__=='__main__':
    s = Solution()
    print s.permuteUnique([2,3,1,1,4])
    print s.permuteUnique([3,3,1,2,3,2,3,1])
