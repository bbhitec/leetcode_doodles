##!/usr/bin/env python
'''
    @author [mst]
    @file   704_binary_search.py
    @brief  leetcode problems series
    704. Binary Search
    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
    You must write an algorithm with O(log n) runtime complexity.

    Constraints:
    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.

    gains:
    -binary search algorithm

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# iterative binary search
# sub: 94%T 73%S
class Solution:
    def search(self, nums: int, target: int) -> int:
        # consider constraint: 1 <= nums.length <= 104
        if len(nums) == 1:
            if target == nums[0]: return 0

        lower = 0
        upper = len(nums) -1

        while lower <= upper:
             # let the middle of search section control search direction
            middle = (upper + lower) //2
            if nums[middle] == target: return middle

            #update boundaries
            if nums[middle] < target:
                lower = middle + 1 # omit the middle!
            else:
                upper = middle -1
        return -1

# a naive, linear time O(n) solution
# sub: 59%T 73%S
class Solution0:
    def search(self, nums: int, target: int) -> int:
        if len(nums) == 1:
            return target == nums[0]
        for i, n in enumerate(nums):
            if target == n:
                return i
        return -1



################## DRIVER
def main():

    sol = Solution()
    nums = [-1,0,3,5,9,12]
    target = 2

    # nums = [2,5]
    # target = 5

    # testing
    print(sol.search(nums,target))




if __name__ == ("__main__"):
    main()
