##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    518_coin_change2
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

    Constraints:
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000

    gains:
    -dynamic programming: bottom -up permutations counting

    @version 2023.02
'''

################## DECL_IMPL

class Solution:
    def change(self, n, c):
        n_perms = [1]+[0]*n
        for coin in c:
            for i in range(coin, n+1):
                n_perms[i] += n_perms[i-coin]
        return n_perms[n]

################## DRIVER
def main():
    sol = Solution()

    # testing
    n,c = 500, [1,2,5]
    print (sol.change(n, c)
)



if __name__ == ("__main__"):
    main()
