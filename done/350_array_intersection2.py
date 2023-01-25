##!/usr/bin/env python
'''
    @author [mst]
    @file   350_array_intersection2.py
    @brief  leetcode problems series
    Given two integer arrays nums1 and nums2, return an array of their intersection.
    Each element in the result must appear as many times as it shows
    in both arrays and you may return the result in any order.

    gains:
    -conditionals, histogram

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# since 0 <= nums1[i], nums2[i] <= 1000, use two appearance histograms to note numbers and then built a list from the data
#
# sub: 25%T 16%S
class Solution:
    def intersect(self, nums1: [int], nums2: [int]) -> [int]:

        vocsize = 1001
        res = []
        voc1 = [0 for i in range(vocsize)]  # demo - initialize n-sized array
        voc2 = [0 for i in range(vocsize)]

        for n in nums1: voc1[n] = voc1[n] + 1
        for n in nums2: voc2[n] = voc2[n] + 1

        for i in range(0,vocsize):
            while (voc1[i] and voc2[i]):
                res.append(i)
                voc1[i] = voc1[i] - 1
                voc2[i] = voc2[i] - 1

        return res

################## DRIVER
def main():

    sol = Solution()


    # testing
    nums1 = [1,2,2,1,10]
    nums2 = [2,2,10]
    print(sol.intersect(nums1,nums2))



if __name__ == ("__main__"):
    main()
