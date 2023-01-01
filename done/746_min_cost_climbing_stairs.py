##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    746. Min Cost Climbing Stairs
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
    
    Gains:
    -dp momoization
    -bottom-up optimization

    features, changelog:
    -initial

    @version 0.1 2023.01
'''


# bottom-up solution (hinted from leetcode community solution)
#
# sub: 85%T 41%S after omitting dp struct: 95%T 412%S
class Solution:
    def minCostClimbingStairs(self, cost: [int]) -> int:
        n = len(cost)
        prev = cost[0]
        last = cost[1]
        
        # dp = []
        # dp.append(cost[0])
        # dp.append(cost[1])
        # # building memoization struct
        # for i in range(2,n):
        #     # print(f"{i=} : {cost[i]=}")
        #     dp.append(cost[i] + min(dp[i-1],dp[i-2]))

        for i in range(2,n):
            curr = cost[i] + min(prev,last)
            prev = last
            last = curr

        return min(prev,last)


################## DRIVER
def main():
    
    sol = Solution()

    # cost = [10,15,20]
    # cost = [1,100,1,1,1,100,1,1,100,1]
    cost = [0,1,2,2]
    res = sol.minCostClimbingStairs(cost)
    print(f"min cost for {cost=} res: {res=}")



if __name__ == ("__main__"):
    main()
