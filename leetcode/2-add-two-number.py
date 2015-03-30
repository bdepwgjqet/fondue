#!/usr/bin/python

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    def getNumber(self, l):
        if l == None:
            return 0
        return 10*self.getNumber(l.next)+l.val

    def getNode(self,u):
        if u < 10:
            return ListNode(u)
        ret = ListNode(u%10)
        ret.next = self.getNode(u/10)
        return ret

    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        a = self.getNumber(l1)
        b = self.getNumber(l2)
        return self.getNode(a+b)

if __name__=='__main__':
    s = Solution()
    a = ListNode(2)
    a.next = ListNode(4)
    a.next.next = ListNode(3)

    b = ListNode(5)
    b.next = ListNode(6)
    b.next.next = ListNode(4)
    ans = s.addTwoNumbers(a, b)
    while ans != None:
        print ans.val
        ans = ans .next

