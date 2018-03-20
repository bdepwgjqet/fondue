#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a%b)

    def fraction(self):
        cur_gcd = self.gcd(self.x, self.y)
        self.x = self.x / cur_gcd
        self.y = self.y / cur_gcd

        if self.y < 0:
            self.x = -1 * self.x
            self.y = -1 * self.y

    def to_string(self):
        return str(self.x) + "/" + str(self.y)

class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        max_pc = 0
        for p in points:
            k_dict = {}
            same_p = 0
            max_kc = 0
            for q in points:
                if p.x == q.x and p.y == q.y:
                    same_p = same_p + 1
                    continue
                k_p = Point(p.x-q.x, p.y-q.y)
                k_p.fraction()
                k = k_p.to_string()
                if k not in k_dict:
                    k_dict[k] = 0
                k_dict[k] = k_dict[k] + 1
                max_kc = max(max_kc, k_dict[k])
            max_pc = max(max_pc, max_kc + same_p)
        return max_pc

s = Solution()
print(s.maxPoints([Point(1,1), Point(-1,-1), Point(2,2), Point(1,2)]))
