#!/usr/bin/python

class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        p = path.split("/")
        ap = []
        for i in p:
            if i == "" or i == '.':
                continue
            elif i == "..":
                if len(ap) > 0:
                    ap.pop()
            else:
                ap.append(i)
        ret = ""
        for i in ap:
            ret += "/"
            ret += i
        return ret if ret != "" else "/"

if __name__=='__main__':
    s = Solution()
    print s.simplifyPath("/a/./b/../../c/")
    print s.simplifyPath("/a/./b/../../../")
