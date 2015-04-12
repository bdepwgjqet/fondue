#!/usr/bin/python

class Solution:

    def dfs(self,now,cur):
        if now == len(self.num):
            self.ans.append(cur[:])
            return
        self.dfs(now+1,cur)
        cur.append(self.num[now])
        self.dfs(now+1,cur)
        cur.pop()

    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        self.num = S
        self.ans = []
        self.num.sort()
        self.dfs(0,[])
        return self.ans

if __name__=='__main__':
    s = Solution()
    print s.subsets([1,2,3])
