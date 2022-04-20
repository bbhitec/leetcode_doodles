#!/usr/bin/env python
"""
[mst] 1_twosum.py 
leetcode problems series

  1. Two Sum
  Given an array of integers, return indices of the two numbers such that
  they add up to a specific target. You may assume that each input would have
  exactly one solution, and you may not use the same element twice.        
  Example:
  Given nums = [2, 7, 11, 15], target = 9,        
  Because nums[0] + nums[1] = 2 + 7 = 9,
  return[0, 1].
log:
-2022.04 [wip]
-2022.01: played with naive implementetion, re-solved
-initial hash-based solution (I think I've copied it from somewhere)

@author: mst
"""
import time

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

class Solution(object):
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
    print ("[mst] leetcode 1. two sum problem")

    s = Solution()
    
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
    

# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()
    
        