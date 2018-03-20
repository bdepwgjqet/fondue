#!/usr/bin/env python
# -*- coding: utf-8 -*-

from queue import PriorityQueue

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        q = PriorityQueue()
        head = ListNode(0)
        cur_head = head
        idx = 0
        for l in lists:
            if l:
                q.put((l.val, idx, l))
                idx = idx + 1
        while not q.empty():
            cur_val, idx, cur_l = q.get()
            cur_node = ListNode(cur_val)
            cur_head.next = cur_node
            cur_head = cur_head.next

            cur_l = cur_l.next
            if cur_l:
                q.put((cur_l.val, idx, cur_l))
        head = head.next
        return head

solution = Solution()
la = ListNode(1)
la.next = ListNode(3)
lb = ListNode(2)
lb.next = ListNode(4)
ans = solution.mergeKLists([la, lb])
while ans:
    print(ans.val)
    ans = ans.next
