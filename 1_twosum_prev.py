# [mst] 1_twosum.py 
# leetcode problems series
# 
#   1. Two Sum
#   Given an array of integers, return indices of the two numbers such that
#   they add up to a specific target. You may assume that each input would have
#   exactly one solution, and you may not use the same element twice.        
#   Example:
#   Given nums = [2, 7, 11, 15], target = 9,        
#   Because nums[0] + nums[1] = 2 + 7 = 9,
#   return[0, 1].
#
# log:
# - initial hash-based solution (I think I've copied it from somewhere)
#

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        nums_hash = {}
        for i, num in enumerate(nums):
            potentialMatch = target - num   # prep the difference

            # check if there is a match
            if potentialMatch in nums_hash:
                return [nums_hash[potentialMatch], i]

            # if not, record the encountered member
            nums_hash[num] = i
        """

# driver
def main():
    print ("[mst] leetcode 1. two sum problem")
 
    s = Solution()
    sum = 9
    arr = [1, 7, 11, 15,2]
    print ("looking for sum:", sum, "in", arr)
    print(s.twoSum(arr, sum))
    

# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()
    
        