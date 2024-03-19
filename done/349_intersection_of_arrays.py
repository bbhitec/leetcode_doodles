##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    349_intersection_of_arrays
    Given two integer arrays nums1 and nums2, return an array of their intersection.
    Each element in the result must be unique and you may return the result in any order.

    gains:
    -basic set logic


    @version 0.1 2024.03
'''

# a version with usin a single set
# assisted
#
# sub: 84 90
class Solution:
    def intersection(self, nums1: [int], nums2: [int]) -> [int]:
        ans = []
        nums1 = set(nums1)

        for num in nums2:
            if num in nums1:
                ans.append(num)
                nums1.remove(num)

        return ans


# make sets out of the lists to have unique values
# then run across to see what numbers appear in both
#
# sub: 12 99
class Solution0:
    def intersection(self, nums1: [int], nums2: [int]) -> [int]:
        set1 = set(nums1)
        set2 = set(nums2)
        ans = []

        for n in set2:
            if n in set1:
                ans.append(n)

        return ans



################## DRIVER
def main():
    sol = Solution()

    # nums1 = [1,2,2,1]
    # nums2 = [2,2]

    nums1 = [4,9,5]
    nums2 = [9,4,9,8,4]

    res = sol.intersection(nums1, nums2)
    print (res)



if __name__ == ("__main__"):
    main()
