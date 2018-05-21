#!/usr/bin/env python
# -*- coding: utf-8 -*-

import heapq

class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        int_max = 2**31
        pq = []
        points = []
        for building in buildings:
            l = building[0]
            r = building[1]
            h = building[2]
            points.append((l, -h, r))
            points.append((r, h, 0))
        points = sorted(points)
        res = [[0, 0]]
        heapq.heappush(pq, (0, int_max))
        for l, h, r in points:
            h = -h
            while l >= pq[0][1]:
                heapq.heappop(pq)
            if h >= 0:
                heapq.heappush(pq, (-h, r))
            if res[-1][1] != -pq[0][0]:
                res.append([l, -pq[0][0]])
        return res[1:]

solution = Solution()
print(solution.getSkyline([ [2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8] ]))
print(solution.getSkyline([[0,2147483647,2147483647]]))
print(solution.getSkyline([[0,2,3],[2,5,3]]))
