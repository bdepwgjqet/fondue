#!/usr/bin/python

class Solution:
    # @param {integer[]} height
    # @return {integer}
    def largestRectangleArea(self, height):
        st = []
        ans = 0
        for i in range(len(height)):
            w = i
            while len(st) > 0:
                x,y,z = st[-1]
                if x < height[i]:
                    break
                ans = max(ans,x*(i-y))
                w = y
                st.pop()
            ans = max(ans,(i-w+1)*height[i])
            st.append((height[i],w,i))
        while len(st) > 0:
            x,y,z = st[-1]
            st.pop()
            ans = max(ans,(len(height)-y)*x)
        return ans


if __name__=='__main__':
    s = Solution()
    print s.largestRectangleArea([2,1,5,6,2,3])
    print s.largestRectangleArea([2,1,2])
    print s.largestRectangleArea([1])
    print s.largestRectangleArea([1,1,1,1])
    print s.largestRectangleArea([3,6,5,7,4,8,1,0])
