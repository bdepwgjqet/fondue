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
    # @param a ListNode
    # @return a ListNode
    def getNext(self,f,s):
        nf = ns = None
        if s.next:
            nf = s.next
            if nf.next:
                ns = nf.next
        return (nf,ns)

    def swapPairs(self, head):
        if head == None:
            return None
        if head.next == None:
            return head
        cur = ListNode(0)
        ret = cur
        f = head
        s = f.next
        while f != None and s !=None:
            (nf,ns) = self.getNext(f,s)
            cur.next = s
            f.next = s.next
            s.next = f
            cur = f
            f = nf
            s = ns
        return ret.next
        
if __name__=='__main__':
    s = Solution()
    a = ListNode(1)
    a.next = ListNode(2)
    a.next.next = ListNode(3)
    a.next.next.next = ListNode(4)
    show(s.swapPairs(a))
