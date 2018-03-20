#!/usr/bin/env python
# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        new_head = ListNode(1)
        new_node = new_head
        while head:
            cur_block_head = None
            cur_block_tail = None

            left_cnt = 0
            tmp_head = head
            while tmp_head and left_cnt < k:
                tmp_head = tmp_head.next
                left_cnt = left_cnt + 1
            if left_cnt < k:
                cur_block_head = head
                cur_block_tail = None
                head = None
            else:
                block_cnt = k
                while head and block_cnt > 0:
                    next_head = head.next
                    head.next = cur_block_head
                    cur_block_head = head
                    if not cur_block_tail:
                        cur_block_tail = head
                    head = next_head
                    block_cnt = block_cnt - 1
            new_node.next = cur_block_head
            new_node = cur_block_tail

        return new_head.next

tl = ListNode(1)
tl.next = ListNode(2)
tl.next.next = ListNode(3)
tl.next.next.next = ListNode(4)
tl.next.next.next.next = ListNode(5)
solution = Solution()
#res_l = solution.reverseKGroup(tl, 2)
res_l = solution.reverseKGroup(tl, 3)
while res_l:
    print(res_l.val)
    res_l = res_l.next
