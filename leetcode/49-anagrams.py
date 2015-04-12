#!/usr/bin/python

class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        mp = {}
        ans = []
        for s in strs:
            ss = ''.join(sorted(s))
            if not mp.has_key(ss):
                mp[ss] = []
            mp[ss].append(s)
        for k in mp:
            v = mp[k]
            if len(v) > 1:
                ans += v
        return ans

if __name__=='__main__':
    s = Solution()
    print s.anagrams(["kjdf","dfjk"])
