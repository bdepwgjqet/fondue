#!/usr/bin/python

class Solution:

    # @return an integer
    def lengthOfLongestSubstring(self, s):
        if len(s) < 1:
            return 0
        l,r = 0,1
        u = set(s[0])
        ret = 1
        while l < len(s) and r < len(s):
            if s[r] in u:
                while l<r:
                    u.remove(s[l])
                    if s[l] == s[r]:
                        l = l + 1
                        break
                    l = l + 1
            u.add(s[r])
            r = r + 1
            ret = max(ret,r-l)
        return ret

if __name__=='__main__':

    s = Solution()
    print s.lengthOfLongestSubstring("abcabcbb")
    print s.lengthOfLongestSubstring("llllllll")
    print s.lengthOfLongestSubstring("biidygcc")
