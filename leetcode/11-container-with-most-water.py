#!/usr/bin/python

class Solution:
    # @return an integer
    def maxArea(self, height):
        l = 0
        r = len(height)-1
        ans = 0
        while l < r:
            ans = max(ans,(r-l)*min(height[r],height[l]))
            if height[r]<height[l]:
                r = r-1
            else:
                l = l+1
        return ans

if __name__=='__main__':
    s = Solution()
    print s.maxArea([1,2,3,4,5,6])
