#!/usr/bin/python

class Solution:

    # @return an integer
    def threeSumClosest(self, num, target):
        num.sort()
        ret = 100000000
        for i in range(len(num)-2):
            if i > 0 and num[i] == num[i-1]:
                continue
            nt = target - num[i]
            l = i + 1
            r = len(num) - 1
            while l < r:
                if num[l]+num[r] == nt:
                    ret = target
                    l = l + 1
                    r = r - 1
                elif num[l]+num[r] < nt:
                    if abs(ret-target) > abs(target-(num[i]+num[l]+num[r])):
                        ret = num[i]+num[l]+num[r]
                    l = l + 1
                else:
                    if abs(ret-target) > abs(target-(num[i]+num[l]+num[r])):
                        ret = num[i]+num[l]+num[r]
                    r = r - 1
        return ret

         
if __name__=='__main__':
    s = Solution()
    print s.threeSumClosest([-1,2,1,-4],1)
