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


Gains:
- python dictionaries: key/value orientation
- sorting and using lists
- algorithm: bucket sort variation

log:
-2022.04.05: snipped solution: https://youtu.be/YPTqKIgVk-k 46.02% t 6.97% s
-2022.04.03: initial attempt
-2022.03.31: created

@author: mst
"""

class Solution0(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        returns the k most frequent elements in a given list.
        initial idea: count frequencies of all members, sort and return most
        frequent since its not bound, we cannot guarantee O(n).
        Also, the lambda expression doesn't seem to work in leetcode :(
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

        res = list(sortedout)[0:k]
        return res

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        returns the k most frequent elements in a given list.
        smart keying: use count (frequency) as a bucket, with a size bound to 
        len(nums), since its the maximum occurences (all nums are the same).
        hence O(n) time. then, just pick the last members for an answer
        """

        # key: number of occurences, value: list of corresponding members
        count_dict = {}

        # index i holds i-frequent member of nums
        freqs = [[] for i in range(len(nums) +1 )]
        

        # count the occurences
        for num in nums:
            if num in count_dict:
                count_dict[num] = count_dict[num] + 1
            else:
                count_dict[num] = 1 # else - add element (not the diff) to hash
        
        # build the buckets: freq[coun] = list of corresponding members
        for n, c in count_dict.items():
            #print (f"{n=},{c=}")
            freqs[c].append(n)

        res = []

        # [demo] run loop from end to start with an index
        for i in range(len(freqs)-1, 0, -1):
            for member in freqs[i]:
                res.append(member)

                # at some point we will reach k elements (bound by freqs size)
                if len(res) == k:
                    return res




# driver
def main():
    print ("[mst] leetcode 347. Top K Frequent Elements")

    '''
    s0 = Solution0()

    # Example 1:
    # Input: nums = [1,1,1,2,2,3], k = 2
    # Output: [1,2]
    nums = [1,1,1,2,2,3]
    k = 2
    result = s0.topKFrequent(nums,k)
    print (f'test: {nums=}, {k=}, {result=}')
    

    nums = [1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,3,3]
    k = 2
    result = s0.topKFrequent(nums,k)
    print (f'test: {nums=}, {k=}, {result=}')
    '''
    
    s = Solution()
    nums = [1,1,1,2,2,3]
    k = 2
    result = s.topKFrequent(nums,k)
    print (f'test: {nums=}, {k=}, {result=}')

    nums = [1,1,1,2,2,2,2,2,3,3,3,3,3]
    k = 2
    result = s.topKFrequent(nums,k)
    print (f'test: {nums=}, {k=}, {result=}')

    

# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()
    
        