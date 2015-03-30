#!/usr/bin/python

class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        if len(L) == 0:
            return []
        dic = {}
        for i in xrange(len(L)):
            if dic.has_key(L[i]):
                dic[L[i]] = dic[L[i]] + 1
            else:
                dic[L[i]] = 1
        l = len(L[0])
        ans = []
        for i in xrange(0,len(S)-l*len(L)+1):
            per = True
            now = {}
            for j in xrange(i,i+l*len(L),l):
                v = S[j:j+l]
                if now.has_key(v):
                    now[v] = now[v] + 1
                else:
                    now[v] = 1
                if dic.has_key(v) and dic[v]>=now[v]:
                    continue
                else:
                    per = False
            if per:
                ans.append(i)
        return ans

if __name__=='__main__':
    s = Solution()
    print s.findSubstring("a",["a"])

