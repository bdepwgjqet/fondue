#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def show(r):
    if r == None:
        return
    print r.val
    show(r.next)

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def rotateRight(self, head, k):
        if k <= 0 or head is None:
            return head
        root =  head
        n = 0
        while root != None:
            n = n + 1
            root = root.next
        k = k%n
        l = head
        r = head
        c = 0
        while r.next != None and c < k:
            r = r.next
            c = c + 1
        if c < k:
            return head
        while r.next != None:
            l = l.next
            r = r.next
        r.next = head
        head = l.next
        l.next = None
        return head

if __name__=='__main__':
    s = Solution()
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    root.next.next.next.next = ListNode(5)
    show(s.rotateRight(root,2))
