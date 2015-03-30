#!/usr/bin/python

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        num.sort()
        ret = []
        print num
        for k in range(len(num)-3):
            if k > 0 and num[k] == num[k-1]:
                continue
            for i in range(k+1,len(num)-2):
                if i > k+1 and num[i] == num[i-1]:
                    continue
                tg = target-num[i]-num[k]
                l = i + 1
                r = len(num) - 1
                while l < r:
                    if num[l]+num[r] == tg:
                        ret.append([num[k],num[i],num[l],num[r]])
                        l = l + 1
                        r = r - 1
                        while l < r and num[l] == num[l-1]:
                            l = l + 1
                        while l < r and num[r] == num[r+1]:
                            r = r - 1
                    elif num[l]+num[r] < tg:
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
    #print s.fourSum([0,0,0,0],0)
    print s.fourSum([-1,0,1,2,-1,-4], -1)
