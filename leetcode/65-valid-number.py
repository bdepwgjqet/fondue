#!/usr/bin/python

class Solution:

    def isONumber(self,s,po,op):
        pre = po
        c = 0
        for i in range(len(s)):
            if po:
                if s[i] == '-' or s[i] == '+':
                    po = False
                    continue
            if ord(s[i]) < ord('0') or ord(s[i]) > ord('9'):
                return False
            c = c + 1
            po = False
        if not op and pre and c == 0:
            return False
        return True

    def noNum(self,s):
        for i in range(len(s)):
            if ord(s[i]) >= ord('0') and ord(s[i]) <= ord('9'):
                return False
        return True

    def isRNumber(self,s,op,np):
        s = s.strip()
        if len(s) == 0:
            return False
        seg = s.split('.')
        if len(seg) > 2:
            return False
        if op:
            if self.noNum(s):
                return False
        if len(seg) == 2:
            if np:
                return False
            if len(seg[0].strip()) == 0 and len(seg[1].strip()) == 0:
                return False
            return self.isONumber(seg[0],True,True) and self.isONumber(seg[1],False,False)
        return self.isONumber(s,True,False)

    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        s = s.strip()
        for i in range(len(s)):
            if s[i] == ' ':
                return False
        seg = s.split('e')
        if len(seg) > 2:
            return False
        elif len(seg) == 2:
            return self.isRNumber(seg[0],False,False) and self.isRNumber(seg[1],False,True)
        return self.isRNumber(s,True,False)
        
if __name__=='__main__':
    s = Solution()
    print s.isNumber("0")
    print s.isNumber("0.1")
    print s.isNumber("abc")
    print s.isNumber("1 a")
    print s.isNumber("2e10")
    print s.isNumber("e")
    print s.isNumber(".1")
    print s.isNumber("ee")
    print s.isNumber(". 1")
    print s.isNumber("-1.")
    print s.isNumber("3-2")
    print s.isNumber("+.8")
    print s.isNumber("1e+")
    print s.isNumber("-.")
    print s.isNumber("6e6.5")
