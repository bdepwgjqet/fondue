#!/usr/bin/python

class Solution:
    def init_info(self,num):
        self.inf = []
        self.inf.append("0")
        for i in range(1,10):
            ans = ""
            pre_add = 0
            for j in range(len(num)):
                v = ord(num[j]) - ord('0')
                now = pre_add + v*i
                pre_add = now / 10
                ans += str(now%10)
            if pre_add > 0:
                ans += str(pre_add)
            self.inf.append(ans)

    def add(self,num1,num2):
        if len(num2) > len(num1):
            return self.add(num2,num1)
        ans = ""
        pre = 0
        i = 0
        while i < len(num1) or pre > 0:
            u = v = 0
            if i < len(num1):
                u = ord(num1[i])-ord('0')
            if i < len(num2):
                v = ord(num2[i])-ord('0')
            ans += str((u+v+pre) % 10)
            pre = (u+v+pre) / 10
            i = i + 1
        return ans

    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
        if (len(num1) < len(num2)):
            return self.multiply(num2,num1)
        self.init_info(num1[::-1])
        ret = "0"
        for i in range(len(num2)):
            now = ord(num2[i])-ord('0')
            c = len(num2) - i - 1
            ret = self.add(ret,'0'*c+self.inf[now])
        return ret[::-1]
        
if __name__=='__main__':
    s = Solution()
    print s.multiply("9","9")
