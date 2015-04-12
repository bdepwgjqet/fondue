#!/usr/bin/python

class Solution:
    # @param S, a string
    # @param T, a string
    # @return a string
    def minWindow(self, S, T):
        l = 0
        r = 0
        mp = {}
        c = 0
        for i in range(len(T)):
            if not mp.has_key(T[i]):
                mp[T[i]] = 0
            mp[T[i]] = mp[T[i]] + 1
        np = {}
        find = False
        while r < len(S) and len(mp) > 0:
            if mp.has_key(S[r]):
                if not np.has_key(S[r]):
                    np[S[r]] = 0
                np[S[r]] = np[S[r]] + 1
                if np[S[r]] == mp[S[r]]:
                    c = c + 1
                if c == len(mp):
                    r = r + 1
                    find = True
                    break
            r = r + 1
        if not find:
            return ""
        np.copy()
        pre = ''
        ans = r - l
        ret = S[l:r]
        while r <= len(S):
            while l <= r:
                if mp.has_key(S[l]):
                    if mp[S[l]] - np[S[l]] >= 0:
                        break
                    else:
                        np[S[l]] = np[S[l]] - 1
                l = l + 1
            if r - l < ans:
                ans = r- l
                ret = S[l:r]
            if r >= len(S):
                break
            if np.has_key(S[r]):
                np[S[r]] = np[S[r]] + 1
            r = r + 1
        return ret
        
if __name__=='__main__':
    s = Solution()
    print s.minWindow("a","b")
    print s.minWindow("a","a")
    print s.minWindow("bba","ab")
