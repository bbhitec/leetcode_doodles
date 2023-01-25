'''
 [mst] 1480_running_sum_1d.py
 1480. Running Sum of 1d Array
 Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 Return the running sum of nums.

 log
 - 2022.11.27: first submission

Created on Nov, 2022
@author: mst
'''


# iterate with in-place modification 31% T 73% S
class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        if not nums:
            return 0
        else:
            for i,n in enumerate(nums[1::],1):
                nums[i] = nums[i-1]+n
            return nums

# simply run and build a result sum 59% T 28% S
class Solution1:
    def runningSum(self, nums: list[int]) -> list[int]:
        if not nums:
            return 0
        else:
            res = [nums[0]]
            for n in nums[1::]:
                res.append(res[-1]+n)
            return res


# driver
def main():
    print ("[mst] 1480_running_sum_1d")

    sol = Solution()

    # testing
    case0 = [1,2,3,4]
    case1 = [1,1,1,1,1]
    case2 = [3,1,2,10,1]
    case = case0
    print (f"checking {case}: {sol.runningSum(case)}")
    print (f"checking {case1}: {sol.runningSum(case1)}")
    print (f"checking {case2}: {sol.runningSum(case2)}")


# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()