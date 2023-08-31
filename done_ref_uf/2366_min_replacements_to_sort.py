##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    2366_min_replacements_to_sort
    You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.
    For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
    Return the minimum number of operations to make an array that is sorted in non-decreasing order.

    Constraints:
    1 <= nums.length <= 105
    1 <= nums[i] <= 109

    gains:
    -[wip] rd the snipped solution
    -[wip] run


    @version 0.1 2023.01
'''

# snipped walkccc
#
# sub 90 79
class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        ans = 0

        max = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            ops = (nums[i] - 1) // max
            ans += ops
            max = nums[i] // (ops + 1)

        return ans

################## DRIVER
def main():
    sol = Solution()

    nums = [1,2,3,4,5]
    # ...
    # k = 2
    # print (f"{piles=} {k=} res: {sol.maxValueOfCoins(piles, k)}")



if __name__ == ("__main__"):
    main()
