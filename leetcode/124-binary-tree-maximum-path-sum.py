#!/usr/bin/env python
# -*- coding: utf-8 -*-

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    inf = 100000000
    def max_path_and_link(self, root):
        max_path = -self.inf
        max_l_link = -self.inf
        max_r_link = -self.inf
        max_link = -self.inf
        if root.left:
            max_l_path, max_l_link = self.max_path_and_link(root.left)
            max_path = max(max_l_path, max_path)
        if root.right:
            max_r_path, max_r_link = self.max_path_and_link(root.right)
            max_path = max(max_path, max_r_path)
        max_link = max(root.val + max_l_link, root.val + max_r_link)
        max_link = max(root.val, max_link)
        max_path = max(max_path, root.val + max_l_link + max_r_link)
        max_path = max(max_path, max_link)
        return (max_path, max_link)
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        max_path, max_link = self.max_path_and_link(root)
        return max_path

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
solution = Solution()
print(solution.maxPathSum(root))
