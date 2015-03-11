#!/usr/bin/python

class Solution:

    def twoSum(self, num, target):
        dic = {}
        for i in range(len(num)):
            dic[num[i]]=i+1
        for i in range(len(num)):
            if dic.has_key(target-num[i]):
                value = dic.get(target-num[i])
                if i+1 == value:
                    continue
                return (i+1,value)
        return (0,0)

if __name__=='__main__':
    s = Solution()
    print s.twoSum(num = [2,7,11,15], target=9)

