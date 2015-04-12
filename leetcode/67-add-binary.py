#!/usr/bin/python

class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        a = a[::-1]
        b = b[::-1]
        ans = ""
        i = 0
        c = 0
        while i < len(a) or i < len(b) or c > 0: 
            ai = 0
            if i < len(a):
                ai = ord(a[i]) - ord('0')
            bi = 0
            if i < len(b):
                bi = ord(b[i]) - ord('0')
            ans += str((ai+bi+c)%2)
            c = (ai+bi+c)/2
            i = i + 1
        return ans[::-1]
        
if __name__=='__main__':
    s = Solution()
    print s.addBinary("1011","101")

