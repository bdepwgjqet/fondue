#!/usr/bin/python

import heapq

#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def show(node):
    if node != None:
        print node.val,"->"
        show(node.next)

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        if k == 0:
            k = 1
        ret = ListNode(0)
        cur = ret
        l = head
        r = head
        while l != None:
            c = 0
            while r.next != None and c < k-1:
                r = r.next
                c = c + 1
            if c < k-1:
                cur.next = l
                break
            nsegl = r.next
            nsegr = r.next

            pre = r.next
            ncur = l
            while l != r:
                nl = l.next
                l.next = pre
                pre = l
                l = nl
            cur.next = l
            l.next = pre

            l = nsegl
            r = nsegr
            cur = ncur
        return ret.next
        
if __name__=='__main__':
    s = Solution()
    a = ListNode(1)
    a.next = ListNode(2)
    a.next.next = ListNode(3)
    a.next.next.next = ListNode(4)
    show(s.reverseKGroup(a,5))
