#!/usr/bin/env python
"""
[mst] 347_topk_freq.py 
leetcode problems series

347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent
elements. You may return the answer in any order. 

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Constraints:
1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

gains:
-dictionaries: key/value orientation, sorting and using for lists

log:
- 2022.03.31: created

@author: mst
"""

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        returns the k most frequent elements in a given list
        """

        # frequency dictionary in format: {key: nums member, value: appearances}
        count_dict = {}

        for num in nums:
            if num in count_dict:
                count_dict[num] = count_dict[num] + 1
            else:
                count_dict[num] = 1 # else - add element (not the diff) to hash 

        # sort by values so the k first members are the most frequent
        sortedout = {key: val for key, val in sorted(count_dict.items(), key = lambda ele: ele[1], reverse = True)}
        #sortedout = sorted(count_dict.items(), key=lambda x:x[1])
        #sortedoutdict = dict(sortedout)

        res = list(sortedout)[0:k]
        return res



# driver
def main():
    print ("[mst] leetcode 347. Top K Frequent Elements")

    s = Solution()

    # Example 1:
    # Input: nums = [1,1,1,2,2,3], k = 2
    # Output: [1,2]
    '''nums = [1,1,1,2,2,3]
    k = 2
    result = s.topKFrequent(nums,k)
    print (f'test: {nums=}, {k=}, {result=}')
    '''


    nums = [1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,3,3]
    k = 2
    result = s.topKFrequent(nums,k)
    print (f'test: {nums=}, {k=}, {result=}')
    
    '''
    sum = 8
    arr = [1, 4, 11, 15,4]
    print ("looking for sum:", sum, "in", arr, "naive")
    start = time.perf_counter()
    print(s.twoSumNaive(arr, sum))
    print (f'naive task ran for {time.perf_counter()-start}')


    print ("looking for sum:", sum, "in", arr, "hash version")
    start = time.perf_counter()
    print(s.twoSum(arr, sum))
    print (f'hash task ran for {time.perf_counter()-start}')

    sum = 9
    arr = [2,7,11,15]
    print ("looking for sum:", sum, "in", arr, "hash version")
    print(s.twoSum(arr, sum))

    '''
    

# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()
    
        