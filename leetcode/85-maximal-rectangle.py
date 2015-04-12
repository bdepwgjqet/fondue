#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of 1 length string
    # @return an integer
    def maximalRectangle(self, matrix):
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        height = []
        ans = 0
        for i in range(n):
            height.append(0)
        for i in range(m):
            for j in range(n):
                height[j] = height[j] + 1 if matrix[i][j] == '1' else 0
            ans = max(ans,self.largestRectangleArea(height))
        return ans

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
    print s.maximalRectangle(["01","01"])
