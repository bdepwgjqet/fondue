#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head): 
        if head == None:
            return None
        ans = ListNode(0)
        ar = ans
        r = head
        while r != None and r.next != None:
            if r.next.val == r.val:
                tmp = r
                while r.next != None and r.next.val == r.val:
                    r = r.next
                r = r.next
                ar.next = tmp
                ar = ar.next
                ar.next = None
            else:
                ar.next = r
                r = r.next
                ar = ar.next
                ar.next = None
        ar.next = r
        return ans.next

def show(a):
    if a == None:
        return
    print a.val
    show(a.next)

if __name__=='__main__':
    s = Solution()
    a = ListNode(1)
    a.next = ListNode(2)
    a.next.next = ListNode(2)
    a.next.next.next = ListNode(3)
    a.next.next.next.next = ListNode(3)
    a.next.next.next.next.next = ListNode(4)
    show(s.deleteDuplicates(a))
