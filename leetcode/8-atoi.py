#!/usr/bin/python

class Solution:
    # @return an integer
    def atoi(self, str):
        str = str.lstrip()
        if str == "":
            return 0
        flag = 1
        if (str[0]=='-'):
            flag = -1
            str = str[1:]
        elif(str[0]=='+'):
            str = str[1:]
        ret = 0
        for i in range(len(str)):
            v = ord(str[i])-ord('0')
            if v > 9 or v < 0:
                break
            ret *= 10
            ret += v
        if ret >= (1<<31):
            if flag < 0:
                ret = (1<<31)
            else:
                ret = (1<<31)-1
        return flag*ret
        
if __name__=='__main__':
    s = Solution()
    print s.atoi("  +0 1 2 3")
    print s.atoi("   -0012a42")
    print s.atoi("9534236469")
    print s.atoi("-1000000003")
