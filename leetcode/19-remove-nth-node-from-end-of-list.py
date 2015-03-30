#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def show(node):
    if node == None:
        return
    print node.val,"->"
    show(node.next)

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        if head == None:
            return None

        now = head
        rm = head
        pr = None
        i = 0
        while now != None and i < n-1:
            i = i+1
            now = now.next
        if now == None:
            return None
        while now.next != None:
            now = now.next
            pr = rm
            rm = rm.next
        if rm == head:
            return head.next
        pr.next = rm.next
        return head
         
if __name__=='__main__':
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    show(s.removeNthFromEnd(head,2))
