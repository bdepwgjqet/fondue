#!/usr/bin/env python
# -*- coding: utf-8 -*-

class CacheNode(object):
    key = None
    value = None
    next_node = None
    pre_node = None
    def __init__(self, key, value):
        self.key = key
        self.value = value

class LRUCache:

    head = None
    node_dict = None
    capacity = None

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.head = CacheNode(0, 0)
        self.head.next_node = self.head
        self.head.pre_node = self.head
        self.node_dict = {}

    def append_node(self, cur_node, new_node):
        cur_next = cur_node.next_node
        cur_node.next_node = new_node

        new_node.pre_node = cur_node
        new_node.next_node = cur_next

        if cur_next:
            cur_next.pre_node = new_node

    def remove_node(self, cur_node):
        cur_pre = cur_node.pre_node
        cur_pre.next_node = cur_node.next_node
        cur_node.next_node.pre_node = cur_pre

    def remove_tail(self):
        tail_node = self.head.pre_node
        self.remove_node(tail_node)
        del self.node_dict[tail_node.key]

    def show_link(self):
        cur_node = self.head.next_node
        print_arr = []
        while cur_node is not self.head:
            print_arr.append("{}, {}, {}".format(cur_node.key, cur_node.value, "->"))
            cur_node = cur_node.next_node
        print("".join(print_arr))

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.node_dict:
            return -1
        cur_node = self.node_dict[key]
        self.remove_node(cur_node)
        self.append_node(self.head, cur_node)
        return cur_node.value

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key not in self.node_dict:
            if len(self.node_dict) == self.capacity:
                self.remove_tail()
            cur_node = CacheNode(key, value)
            self.append_node(self.head, cur_node)
            self.node_dict[key] = cur_node
        else:
            cur_node = self.node_dict[key]
            cur_node.value = value
            self.remove_node(cur_node)
            self.append_node(self.head, cur_node)

cache = LRUCache(2)
cache.put(1, 1)
cache.show_link()
cache.put(2, 2)
cache.show_link()
print(cache.get(1))
cache.show_link()
cache.put(3, 3)
cache.show_link()
print(cache.get(2))
cache.put(4, 4)
print(cache.get(1))
print(cache.get(3))
print(cache.get(4))
