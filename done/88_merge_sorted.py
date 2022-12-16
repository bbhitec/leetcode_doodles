##!/usr/bin/env python
'''
    @author [mst]
    @file   88_merge_sorted.py    
    @brief  leetcode problems series
    88. Merge Sorted Array
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
    and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.
    The final sorted array should not be returned by the function, but instead be
    stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
    where the first m elements denote the elements that should be merged, and the last n
    elements are set to 0 and should be ignored. nums2 has a length of n.

    Gains:
    -ponter/index arbitration

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# simple O(n) solution: traverse each sorted array together and
# decide which member shoul be merged at current index
#
# sub: 91%T 86%S
class Solution:
    def merge(self, nums1: [int], m: int, nums2: [int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        nums = []
        i = 0
        i1 = 0
        i2 = 0

        while i < m + n and i2 < n:
            if (nums2[i2] < nums1[i1]) or (i1 >= m):
                nums.append(nums2[i2])
                i2 = i2 + 1
            else:
                nums.append(nums1[i1])
                i1 = i1 + 1
            i = i + 1

        # handle any remaining tail
        while i < m + n and i1 < m:
            nums.append(nums1[i1])
            i1 = i1 + 1


        # copy result to needed destination
        for i, n in enumerate(nums):
            nums1[i] = n

        print(f"{nums=}")


################## DRIVER
def main():
    print ("[mst]")
    
    sol = Solution()

    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    sol.merge(nums1, m, nums2, n)

    nums1 = [2,0]
    m = 1
    nums2 = [1]
    n = 1
    sol.merge(nums1, m, nums2, n)



if __name__ == ("__main__"):
    main()
