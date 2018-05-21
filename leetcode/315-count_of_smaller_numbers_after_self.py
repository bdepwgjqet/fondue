#!/usr/bin/env python
# -*- coding: utf-8 -*-


class Solution:
    def merge_sort(self, s_nums):
        if len(s_nums) <= 1:
            return s_nums
        mid = int((len(s_nums)-1) / 2)
        l_nums = s_nums[0:mid+1]
        r_nums = s_nums[mid+1:]

        l_nums = self.merge_sort(l_nums)
        r_nums = self.merge_sort(r_nums)
        s_nums = []
        l_idx = 0
        r_idx = 0
        sum_r = 0
        while True:
            if l_idx == len(l_nums) and r_idx == len(r_nums):
                break
            l_x, l_y, l_i = l_nums[l_idx] if l_idx < len(l_nums) else (None, None, None)
            r_x, r_y, r_i = r_nums[r_idx] if r_idx < len(r_nums) else (None, None, None)
            choose_l = True
            if l_x is None:
                choose_l = False
            elif r_x is not None and l_x > r_x:
                choose_l = False
            if choose_l:
                l_y = sum_r + l_y
                s_nums.append((l_x, l_y, l_i))
                l_idx = l_idx + 1
            else:
                sum_r = sum_r + 1
                s_nums.append((r_x, r_y, r_i))
                r_idx = r_idx + 1
        return s_nums
        
    def countSmaller(self, nums):
        s_nums = [(x, 0, idx) for idx, x in enumerate(nums)]
        s_nums = self.merge_sort(s_nums)
        ans = [ 0 for x in nums]
        for x, sum, i in s_nums:
            ans[i] = sum
        return ans

s = Solution()
print(s.countSmaller([5, 2, 6, 1]))
