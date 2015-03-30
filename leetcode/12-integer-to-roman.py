#!/usr/bin/python

class Solution:
    # @return a string
    def intToRoman(self, num):
        radix = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"] 
        value = [1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1]
        ret = ""
        for i in range(len(radix)):
            while(num >= value[i]):
                ret += radix[i]
                num -= value[i]
        return ret

if __name__=='__main__':
    s = Solution()
    print s.intToRoman(4)
