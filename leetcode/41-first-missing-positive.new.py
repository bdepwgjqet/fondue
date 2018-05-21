#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def trans(self, idx, nums):
        cur = nums[idx]
        if cur == idx + 1:
            return
        if cur <= 0 or cur > len(nums):
            return
        target = nums[cur-1]
        if target == cur:
            return
        nums[cur-1] = cur
        nums[idx] = target
        self.trans(idx, nums)

    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for idx, x in enumerate(nums):
            if x != idx + 1:
                self.trans(idx, nums)
        for idx, x in enumerate(nums):
            if x != idx + 1:
                return idx + 1
        return len(nums) + 1

solution = Solution()
print(solution.firstMissingPositive([1,2,0]))
print(solution.firstMissingPositive([3,4,-1,-1]))
