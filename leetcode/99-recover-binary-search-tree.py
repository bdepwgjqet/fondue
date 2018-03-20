#!/usr/bin/env python
# -*- coding: utf-8 -*-

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    first = None
    second = None
    pre = None
    def dfs(self, now):
        if now.left:
            self.dfs(now.left)
        if self.pre and self.pre.val > now.val:
            if self.first is None:
                self.first = self.pre
            self.second = now
        self.pre = now
        if now.right:
            self.dfs(now.right)

    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.dfs(root)
        if self.first and self.second:
            tmp = self.first.val
            self.first.val = self.second.val
            self.second.val = tmp

solution = Solution()
tree = TreeNode(2)
tree.left = TreeNode(0)
tree.right = TreeNode(1)
solution.recoverTree(tree)
print(tree.left.val, tree.val, tree.right.val)
