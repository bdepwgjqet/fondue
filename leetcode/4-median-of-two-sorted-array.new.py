#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n = len(nums1) + len(nums2)
        k = int(n / 2)
        if n % 2 == 1:
            return self.find_kth_of_two_sorted_array(
                nums1, nums2, k+1
            )
        else:
            num1 = self.find_kth_of_two_sorted_array(
                nums1, nums2, k
            )
            num2 = self.find_kth_of_two_sorted_array(
                nums1, nums2, k+1
            )
            return float(num1 + num2) / 2.0

    def find_kth_of_two_sorted_array(self, nums1, nums2, k):
        if len(nums1) == 0:
            return nums2[k-1]
        if len(nums2) == 0:
            return nums1[k-1]
        if k == 1:
            return nums1[0] if nums1[0] < nums2[0] else nums2[0]
        medium = int(k / 2)
        idx1 = medium if medium < len(nums1) else len(nums1)
        idx2 = medium if medium < len(nums2) else len(nums2)
        # print(idx1, idx2, k)
        if nums1[idx1-1] < nums2[idx2-1]:
            return self.find_kth_of_two_sorted_array(
                nums1[idx1:], nums2, k-idx1)
        else:
            return self.find_kth_of_two_sorted_array(
                nums1, nums2[idx2:], k-idx2)


solution = Solution()
print(solution.findMedianSortedArrays([1, 3], [2]))
print(solution.findMedianSortedArrays([1, 2], [3, 4]))
