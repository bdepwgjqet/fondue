#!/usr/bin/python

class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        num.sort()
        ret = []
        for i in range(len(num)-2):
            if i > 0 and num[i] == num[i-1]:
                continue
            target = -num[i]
            l = i + 1
            r = len(num) - 1
            while l < r:
                if num[l]+num[r] == target:
                    ret.append([num[i],num[l],num[r]])
                    l = l + 1
                    r = r - 1
                    while l < r and num[l] == num[l-1]:
                        l = l + 1
                    while l < r and num[r] == num[r+1]:
                        r = r - 1
                elif num[l]+num[r] < target:
                    l = l + 1
                    while l < r and num[l] == num[l-1]:
                        l = l + 1
                else:
                    r = r - 1
                    while l < r and num[r] == num[r+1]:
                        r = r - 1
        return ret

         
if __name__=='__main__':
    s = Solution()
    print s.threeSum([-1,0,1,2,-1,-4])
