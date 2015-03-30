#!/usr/bin/python

class Solution:

    def dfs(self, digits, con):
        if len(digits) == 0:
            self.ret.append(con)
            return
        now = ord(digits[0])-ord('0')
        if now == 1:
            self.dfs(digits[1:],con)
        for i in range(len(self.nmap[now])):
            self.dfs(digits[1:],con+self.nmap[now][i])

    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if len(digits) == 0:
            return []
        self.nmap = [" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        self.ret = []
        self.dfs(digits,"")
        return self.ret

if __name__=='__main__':
    s = Solution()
    print s.letterCombinations("23")
