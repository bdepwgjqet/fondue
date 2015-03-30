#!/usr/bin/python

class Solution:
    # @return a boolean
    def dfs(self,s,p):
        ls = len(s)
        lp = len(p)
        if self.dp[ls][lp] != None:
            return self.dp[ls][lp]
        if len(p) == 0:
            self.dp[ls][lp]=(len(s) == 0)
            return self.dp[ls][lp]
        id = p.find('*')
        if id == 0:
            self.dp[ls][lp]=self.dfs(s,p[1:])
            return self.dp[ls][lp]
        if id == -1:
            if len(s) != len(p):
                self.dp[ls][lp]=False
                return self.dp[ls][lp]
            for i in range(len(s)):
                if p[i] == '.':
                    continue
                if s[i]!=p[i]:
                    self.dp[ls][lp]=False
                    return self.dp[ls][lp]
            self.dp[ls][lp]=True
            return self.dp[ls][lp]

        if len(s) < id-1:
            self.dp[ls][lp]=False
            return self.dp[ls][lp]

        for i in range(id-1):
            if p[i] == '.':
                continue
            if s[i] != p[i]:
                self.dp[ls][lp]=False
                return self.dp[ls][lp]

        ret = False
        for i in range(id,len(s)+2):
            ret = ret or self.dfs(s[i-1:],p[id+1:])
            if p[id-1] == '.':
                continue
            if i-1 < len(s) and s[i-1] != p[id-1]:
                break
        self.dp[ls][lp]=ret
        return self.dp[ls][lp]

    def isMatch(self, s, p):
        self.dp = []
        for i in range(len(s)+1):
            self.dp.append([])
            for j in range(len(p)+1):
                self.dp[i].append(None)
        return self.dfs(s,p)

if __name__=='__main__':
    s = Solution()
    print s.isMatch("aaa", "ab*a")

    print s.isMatch("aa","a")
    print s.isMatch("aa","aa")
    print s.isMatch("aaa","aa")
    print s.isMatch("aa", "a*")
    print s.isMatch("aa", ".*")
    print s.isMatch("ab", ".*")
    print s.isMatch("aab", "c*a*b")
    print s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c")
    print s.isMatch("a", "ab*")

    print s.isMatch("bbab", "b*a*")
