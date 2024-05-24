##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    2357_make_arr_zero
    You are given a non-negative integer array nums. In one operation, you must:

    Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
    Subtract x from every positive element in nums.
    Return the minimum number of operations to make every element in nums equal to 0.

    also seen at: https://www.youtube.com/watch?v=VixYfv0UEyE

    gains:
    -basic python iteration
    -lists and sets logic in python

    @version 2023.01
'''


import numpy as np


################## DECL_IMPL


# naive approach: sort the array and subtract eacn number from the rest
# of the array while counting ops
#
# unsubbed
class Solution:
    def minimumOperations(self, nums: [int]) -> int:
        nums.sort()

        subs = 0
        nextsub = 0
        for i in range(len(nums)):
            if not any(nums):
                return subs

            if nums[i] == 0:
                continue

            nextsub = nums[i]
            for j in range(i,len(nums)):
                nums[j] = nums[j] - nextsub
            subs += 1

        return subs


# using sets: build a unique set from the list, the number of all its elements
# besides zero are the number of subtractions
#
# sub 76 89
class Solution:
    def minimumOperations(self, nums: [int]) -> int:
        asaset = set(nums)

        if 0 in asaset:
            return len(asaset) - 1
        return len(asaset)



################## DRIVER
def main():

    s = Solution()
    nums = [1,5,0,3,5,6]

    res = s.minimumOperations(nums)
    print(f"{res=}")


if __name__ == ("__main__"):
    main()
