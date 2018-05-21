#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Node:
    def __init__(self, value=None):
        self.value = value
        self.pre = None
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    def append(self, x):
        if self.head is None:
            self.head = Node(x)
            self.tail = self.head
        else:
            cur_node = Node(x)
            self.tail.next = cur_node
            cur_node.pre = self.tail
            self.tail = cur_node
    def get_last_one(self):
        return self.tail.value
    def remove_one_node(self, node):
        pre_node = node.pre
        next_node = node.next
        if not pre_node and not next_node:
            self.head = None
            self.tail = None
        else if not pre_node:
            self.head = next_node
            self.head.pre = None
        else if not next_node:
            self.tail = pre_node
            self.tail.next = None
        else:
            pre_node.next = next_node
            next_node.pre = pre_node
        del node
        
    def remove_last_one(self):
        self.remove_node(self.tail)
    
        
class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cur_c = 0
        self.min_freq = 0
        self.freq_to_key_list = {}
        self.key_to_freq = {}
        self.key_to_freq_node = {}
    
    def remove_low_freq(self):
        freq_list = self.freq_to_key_list[self.low_freq]
        cur_key = freq_list.get_last_one()
        freq_list.remove_last_one()
        del self.key_to_freq[cur_key]
        del self.key_to_freq_node[cur_key]
        self.cur_c = self.cur_c - 1
        self.min_freq = 1
    def add_freq(self, key):
        cur_node = self.key_to_freq_node[key]
        cur_freq, value = self.key_to_freq[key]
        self.freq_to_key_list[cur_freq].remove_one_node(cur_node)
        cur_freq = cur_freq + 1
        self.freq_to_key_list[cur_freq].append(key)
        self.key_to_freq[key] = cur_freq, value
        self.key_to_freq_node = self.freq_to_key_list[cur_freq].tail
    def get(self, key):
        if key not in self.key_to_freq:
            return -1
        self.add_freq(key)
        freq, value = self.key_to_freq[key]
        return value
    def put(self, key, value):
        if key in self.key_to_freq:
            freq, p_value = self.key_to_freq[key]
            self.key_to_freq[key] = (freq, value)
            return
        if self.cur_c == self.capacity:
            self.remove_low_freq()
        self.key_to_freq[key] = (1, value)
        if 1 not in self.freq_to_key_list:
            self.freq_to_key_list[1] = LinkedList()
        self.freq_to_key_list[1].append(value)
        self.key_to_freq_node[key] = self.freq_to_key_list[1].tail
        self.min_freq = 1
