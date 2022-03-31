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
        dict = {}

        for num in nums:
            if num in dict:
                dict[num] = dict[num] + 1
            else:
                dict[num] = 1 # else - add element (not the diff) to hash 

        # sort by values so the k first members are the most frequent
        #sortedout = {key: val for key, val in sorted(dict.items(), key = lambda ele: ele[1], reverse = True)}
        sortedout = sorted(dict.items(), key=lambda x:x[1])
        sortedoutdict = dict(sortedout)

        res = list(sortedoutdict)[0:k]
        return res





        



''''''
#[here] check performances..., use the %time thing
def perf_count_decorator(func):
    '''[demo] function performance timer wrapper'''

    def inner(*args, **kwargs):
        '''decorator inner functions (can access outer functions)'''
        start = time.perf_counter() # [bp] time the start with performance counter
        func(*args, **kwargs)
        diff = time.perf_counter()-start
        print (f'task {func.__name__} ran for {diff} secs')
    return inner    # this is the wrapper call

class SolutionZ(object):
    def twoSumNaive(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        naive: run a nested loop to to check all sum combinations
        ~6000ms runtime on leetcode
        """ 
        for i, vali in enumerate(nums):
            for j, valj in enumerate(nums):
                if (i != j): # can't use same element twice
                    print (f'{i=} {j=} {(vali+valj)=}')
                    if (vali+valj == target) and (i!=j):
                        return [i,j]

    def twoSum(self, nums, target):        
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        hash/dictionary solution: use the list value as a member,
        and its index as a value, while checking difference for every
        other value (single list pass)
        """
        diff_hash = {}
        # run nums
        for i, vali in enumerate(nums):
            diff = target - vali    # calc diff
            if diff in diff_hash:   # see if matched
                return [diff_hash[diff], i] # if yes - return indices
            diff_hash[vali] = i # else - add element (not the diff) to hash   
        
        # case of no match found?  (not required since every input has a solution)

# driver
def main():
    print ("[mst] leetcode 347. Top K Frequent Elements")

    s = Solution()

    # Example 1:
    # Input: nums = [1,1,1,2,2,3], k = 2
    # Output: [1,2]
    nums = [1,1,1,2,2,3]
    k = 2
    result = s.topKFrequent(nums,k)
    print (result)


    nums = [1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,3,3]
    k = 2
    result = s.topKFrequent(nums,k)
    print (result)
    
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
    
        