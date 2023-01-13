##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    167_two_sum_sorted.py
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
    Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
    The tests are generated such that there is exactly one solution. You may not use the same element twice.
    Your solution must use only constant extra space.

    gains:
    -python pointer action
    -algorithmic two-pointers thinking

    @version 0.1 2023.01
'''

# Navigate two pointers from both left and right ends of the array,
# if the corresponding sum is greater than the target, nudge the right pointer (decreasing the sum). Otherwise, nudge the left pointer. Do this until the target is found and return the indices
#
# sub: 93%T 88%S
class Solution:
    def twoSum(self, numbers: [int], target: int) -> [int]:
        size = len(numbers)
        l = 0
        r = size-1

        while (l<r):
            sum = numbers[l] + numbers[r]
            if (sum) == target:
                return [l+1,r+1]
            elif sum > target:
                r = r-1
            else:
                l = l+1
        return [-1,-1]


################## DRIVER
def main():

    sol = Solution()

    # numbers, target = [2,7,11,15], 9
    # numbers, target = [2,3,4], 6
    numbers, target = [-1,0], -1

    print(f"{sol.twoSum(numbers, target)=}")


if __name__ == ("__main__"):
    main()
