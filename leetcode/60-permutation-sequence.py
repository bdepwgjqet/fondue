#!/usr/bin/python

class Solution:
    def jie(self,n):
        if n <= 1:
            return 1
        return self.jie(n-1)*n
    # @return a string
    def getPermutation(self, n, k):
        ans = ""
        st = set([])
        for i in range(n):
            c = 0
            now = -1
            for j in range(n):
                if j in st:
                    continue
                if k <= c*self.jie(n-i-1):
                    break
                now = j
                c = c + 1
            st.add(now)
            k -= (c-1)*self.jie(n-i-1)
            ans = ans + str(now+1)
        return ans


if __name__=='__main__':
    s = Solution()
    print s.getPermutation(5,3)
