#!/usr/bin/python

class Solution:
    # @param words, a list of strings
    # @param L, an integer
    # @return a list of strings
    def fullJustify(self, words, L):
        if L == 0:
            return [""]
        i = 0
        ans = []
        while i < len(words):
            l = 0
            w = 0
            sp = 0
            li = []
            while l+sp < L and i<len(words):
                nx = l+sp+1+len(words[i]) if w > 0 else l+sp+len(words[i])
                if nx > L:
                    break
                li.append(words[i])
                l += len(words[i])
                w = w + 1
                sp = w - 1
                i = i + 1
            space = 0
            mod = 0
            if i == len(words):
                space = 1
            elif sp > 0:
                space = (L - l)/sp
                mod = (L-l)%sp
            now = ""
            for j in range(len(li)):
                now += li[j]
                if j < len(li) - 1:
                    now += " "*space
                    now  = now + " " if j < mod else now
            if len(now) < L:
                now += " "*(L-len(now))
            ans.append(now[:])
        return ans

        
if __name__=='__main__':
    s = Solution()
    print s.fullJustify(["This", "is", "an", "example", "of", "text", "justification."],16)
    print s.fullJustify([""],0)
    print s.fullJustify(["a"],1)
    print s.fullJustify(["What","must","be","shall","be."], 12)
    print s.fullJustify(["Imagination","is","more","important","than","knowledge."], 14)
