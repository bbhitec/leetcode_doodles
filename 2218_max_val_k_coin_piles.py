##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    2218_max_val_k_coin_piles
    There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.
    In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.
    Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

    gains:
    -[wip] rd the snipped solution


    @version 0.1 2023.01
'''

# snipped
#
# sub 77 25
class Solution:
    def maxValueOfCoins(self, piles: [[int]], k: int) -> int:
        from functools import lru_cache
        @lru_cache(None)
        def dp(i: int, k: int) -> int:
            if i == len(piles) or k == 0:
                return 0

            ans = dp(i + 1, k)
            val = 0

            for j in range(min(len(piles[i]), k)):
                val += piles[i][j]
                ans = max(ans, val + dp(i + 1, k - j - 1))

            return ans

        return dp(0, k)

################## DRIVER
def main():
    sol = Solution()

    piles = [[1,100,3],[7,8,9]]
    k = 2
    print (f"{piles=} {k=} res: {sol.maxValueOfCoins(piles, k)}")



if __name__ == ("__main__"):
    main()
