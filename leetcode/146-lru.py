#!/usr/bin/env python
# -*- coding: utf-8 -*-

import collections


class LRUCache:

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.key_dict = {}
        self.node_list = collections.OrderedDict()

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.key_dict:
            print(-1)
            return -1
        value = self.node_list.pop(key)
        self.node_list[key] = value
        print(self.key_dict[key])
        return self.key_dict[key]
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.key_dict:
            self.key_dict[key] = value
            self.node_list.pop(key)
            self.node_list[key] = value
        else:
            if self.capacity == len(self.key_dict):
                tmpk, tmpv = self.node_list.popitem(last=False)
                del self.key_dict[tmpk]
            self.key_dict[key] = value
            self.node_list[key] = value

lru = LRUCache(2)

lru.put(1, 1);
lru.put(2, 2);
lru.get(1);       # returns 1
lru.put(3, 3);    # evicts key 2
lru.get(2);       # returns -1 (not found)
lru.put(4, 4);    # evicts key 1
lru.get(1);       # returns -1 (not found)
lru.get(3);       # returns 3
lru.get(4);       # returns 4
