#!/usr/bin/python

class Solution:
    # @param num, a list of integer
    # @return nothing (void), do not return anything, modify num in-place instead.
    def nextPermutation(self, num):
        if len(num) <= 1:
            return
        idx = len(num) - 2
        while idx >= 0 and num[idx] >= num[idx+1]:
            idx = idx -1
        if idx < 0:
            num.reverse()
            return
        nid = idx + 1
        lid = idx + 1
        while lid < len(num):
            if num[lid] > num[idx] and num[lid] <= num[nid]:
                nid = lid
            lid = lid + 1
        num[idx],num[nid] = num[nid],num[idx]
        l = idx + 1
        r = len(num) - 1
        while l < r:
            num[l],num[r] = num[r],num[l]
            l = l + 1
            r = r - 1
        print num

if __name__=='__main__':
    s = Solution()
    #print s.nextPermutation([3,2,1])
    #print s.nextPermutation([2,3,1,3,3])
    print s.nextPermutation([100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1])

 	

