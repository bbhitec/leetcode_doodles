##!/usr/bin/env python
'''
    @author [mst]
    @file   70_climbing_stairs.py
    @brief  leetcode problems series
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    gains:
    -dp, memoization

    features, changelog:
    -2022.11: -submission

    @version 0.1 2022.11
'''


import time



# memoized dynamic programming solution: record every calculated number as we go
#
# sub: 95%T 57%S
class Solution:
    def climbStairs(self, n: int) -> int:

        memo = {1:1,2:2}

        for i in range(3,n+1):
            memo[i] = memo[i-1] + memo[i-2]

        return memo[n]

# straightforward recursive solution. this yielded time exeeding error to
# imply the need for memoization
#
# sub with lru_cache: 35%T 57%S
class Solution0:
    # from functools import lru_cache
    # @lru_cache(maxsize=5)
    def climbStairs(self, n: int) -> int:
        if n == 1 : return 1
        if n == 2 : return 2

        return self.climbStairs(n-1) + self.climbStairs(n-2)


################## DRIVER
def main():
    sol = Solution()

    # testing
    n = 38
    start = time.perf_counter() # [bp] time the start with performance counter
    res = sol.climbStairs(n)
    diff = time.perf_counter()-start
    print (f'task for {n=} resulted {res=} ran for {diff} secs')


if __name__ == ("__main__"):
    main()
