#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def show(l):
    if l == None:
        return
    print l.val,"->"
    show(l.next)

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        ret = None
        head = None
        while l1 != None or l2 != None:
            now = None
            if l1 == None:
                now = l2
                l2 = None
            elif l2 == None:
                now = l1
                l1 = None
            elif l1.val < l2.val:
                now = l1
                l1 = l1.next
            else:
                now = l2
                l2 = l2.next
            if head == None:
                head = now
                ret = head
            else:
                ret.next = now
                ret = ret.next
        return head
        
if __name__=='__main__':
    s = Solution()
    l1 = ListNode(1)
    l1.next = ListNode(3)
    l2 = ListNode(2)
    l2.next = ListNode(4)
    show(s.mergeTwoLists(l1,l2))
