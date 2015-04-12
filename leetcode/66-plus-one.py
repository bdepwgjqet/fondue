#!/usr/bin/python

class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        digits = digits[::-1]
        i = 0
        c = 1
        while c > 0:
            if i == len(digits):
                digits.append(0)
            nc = (digits[i]+c)/10
            digits[i] = (digits[i]+c)%10
            c = nc
            i = i + 1
        return digits[::-1]
        
if __name__=='__main__':
    s = Solution()
    print s.plusOne([3,2,9])
