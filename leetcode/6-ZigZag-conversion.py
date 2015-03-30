#!/usr/bin/python

class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows <= 1:
            return s
        ret = "".join([s[i] for i in range(0,len(s),nRows+nRows-2)])
        for j in range(1,nRows-1):
            a = [s[i] for i in range(j,len(s),nRows+nRows-2)]
            b = [s[i] for i in range(nRows+nRows-2-j,len(s),nRows+nRows-2)]
            for i in range(len(a)):
                ret += a[i]+b[i] if i<len(b) else a[i]
        ret += "".join([s[i] for i in range(nRows-1,len(s),nRows+nRows-2)])
        return ret

if __name__=='__main__':
    s = Solution()
    print s.convert("PAYPALISHIRING",3)
    print s.convert("ABCDE",4)
