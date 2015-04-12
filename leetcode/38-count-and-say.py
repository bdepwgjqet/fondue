#!/usr/bin/python

import re

class Solution:

    def gen(self,now):
        return "".join([str(len(i.group(0)))+i.group(1) for i in re.finditer(r"(\d)\1*",now)])

    # @return a string
    def countAndSay(self, n):
        now = "1"
        if n <= 1:
            return now
        for i in range(n - 1):
            now = self.gen(now)
        return now

if __name__=='__main__':
    s = Solution()
    print s.countAndSay(3)
    print s.countAndSay(10)
