##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    977_square_sorted_array
    Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    Gains:
    -simple python array manipulation

    features, changelog:
    -initial

    @version 0.1 2023.01
'''


# sub: 96T 77S
class Solution:
    def sortedSquares(self, nums: [int]) -> [int]:
        squares = []
        for n in nums:
            squares.append(n*n)
        squares.sort()
        return squares


################## DRIVER
def main():

    sol = Solution()

    nums = [-4,-1,0,3,10]
    res = sol.sortedSquares(nums)
    print(f"testing {nums=} : {res}")



if __name__ == ("__main__"):
    main()
