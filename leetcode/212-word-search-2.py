#!/usr/bin/env python
# -*- coding: utf-8 -*-

class TreeNode(object):
    is_tail = False
    idx = -1 
    childrens = {}

class TrieTree(object):
    head = TreeNode()

    def add_word(self, word, word_idx):
        cur_node = self.head
        for idx, c in enumerate(word):
            if c not in cur_node.childrens:
                cur_node.childrens[c] = TreeNode()
                cur_node.childrens[c].childrens = {}
            if idx == len(word) - 1:
                cur_node.childrens[c].idx = word_idx
                cur_node.childrens[c].is_tail = True
            cur_node = cur_node.childrens[c]

class Solution:
    bm = 0
    bn = 0
    board = None
    vis = []
    vis_idx = 0
    find_words = None

    directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

    def in_board(self, x, y):
        if x < 0 or x >= self.bm:
            return False
        if y < 0 or y >= self.bn:
            return False
        return True

    def dfs(self, x, y, node):
        if node.is_tail:
            self.find_words.add(node.idx)
        #print(node.childrens)
        #print(x, y, self.board[x][y], node.is_tail, node.idx, self.vis_idx)
        self.vis[x][y] = self.vis_idx

        for dx, dy in self.directions:
            nx = dx + x
            ny = dy + y
            if not self.in_board(nx, ny):
                continue
            if self.vis[nx][ny] == self.vis_idx:
                continue
            if self.board[nx][ny] not in node.childrens:
                continue
            next_node = node.childrens[self.board[nx][ny]]
            self.dfs(nx, ny, next_node)
        self.vis[x][y] = 0

    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        self.find_words = set()
        self.bm = len(board)
        self.bn = len(board[0])
        self.board = board
        if self.bm == 0:
            return []
        self.vis = [[0 for x in range(self.bn)] \
            for y in range(self.bm)]
        tt = TrieTree()
        tt.head.childrens = {}
        for idx, word in enumerate(words):
            tt.add_word(word, idx)
        self.vis_idx = 1
        for i in range(self.bm):
            for j in range(self.bn):
                cur = self.board[i][j]
                if cur in tt.head.childrens:
                    self.dfs(i, j, tt.head.childrens[cur])
                    self.vis_idx = self.vis_idx + 1
        find_words_str = []
        for idx in self.find_words:
            if idx < 0 or idx >= len(words):
                continue
            find_words_str.append(words[idx])
        return find_words_str

board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
solution = Solution()
"""
finds = solution.findWords(board, ["oath","pea","eat","rain"])
print(finds)
finds = solution.findWords([['a']], ['a'])
print(finds)
finds = solution.findWords([['a']], ['ab'])
print(finds)
board = [["a","b","c"],["a","e","d"],["a","f","g"]]
arr = ["abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"]
finds = solution.findWords(board, arr)
print(finds)
"""
board = [["a","b"],["a","a"]]
arr = ["aba","baa","bab","aaab","aaa","aaaa","aaba"]
finds = solution.findWords(board, arr)
print(finds)
