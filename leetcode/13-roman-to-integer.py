#!/usr/bin/python

class Solution:
    # @return an integer
    def romanToInt(self, s):
        radix = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"] 
        value = [1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1]
        ret = 0
        pos = 0
        for i in range(len(radix)):
            while True:
                nx = s.find(radix[i],pos)
                if nx != pos:
                    break
                ret += value[i]
                pos += len(radix[i])
        return ret

if __name__=='__main__':
    s = Solution()
    print s.romanToInt("XCIX")
