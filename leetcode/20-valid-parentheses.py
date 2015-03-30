#!/usr/bin/python

class Solution:
    # @return a boolean
    def isValid(self, s):
        self.stack = []
        for i in range(len(s)):
            if s[i] == '[':
                self.stack.append(']')
            elif s[i] == '(':
                self.stack.append(')')
            elif s[i] == '{':
                self.stack.append('}')
            elif len(self.stack) <= 0:
                return False
            elif s[i] == ']':
                if self.stack[-1] != ']':
                    return False
                self.stack.pop()
            elif s[i] == ')':
                if self.stack[-1] != ')':
                    return False
                self.stack.pop()
            elif s[i] == '}':
                if self.stack[-1] != '}':
                    return False
                self.stack.pop()
        if len(self.stack) == 0:
            return True
        return False
         
if __name__=='__main__':
    s = Solution()
    print s.isValid("([])")
    print s.isValid("(])")
