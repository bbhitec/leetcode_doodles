##!/usr/bin/env python
'''
    @author [mst]
    @file   121_best_time_buy_stock.py    
    @brief  leetcode problems series
    121. Best Time to Buy and Sell Stock
    
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing
    a different day in the future to sell that stock. Return the maximum profit you can
    achieve from this transaction. If you cannot achieve any profit, return 0.

    gains:
    -py loops
    -conditionals

    features, changelog:
    -2022.11: -submission

    @version 0.1 2022.11
'''


# simple solution: run a a max and a min and note the maximal difference.
# a local max will be reset upon new min found
# sub: 77% T 39% S
class Solution:
    def maxProfit(self, prices) -> int:
        if not prices:
            return 0

        last_min =  last_max = prices[0]
        max_profit =  0

        for i, n in enumerate(prices):
            if last_min > n:
                last_min = last_max = n # reset the sale point on o new buy point
            if last_max < n:
                last_max = n
                if last_max - last_min > max_profit:
                    max_profit = last_max - last_min

        return max_profit




################## DRIVER
def main():
    print ("[mst] 121_best_time_buy_stock")
    
    sol = Solution()
       
    # testing
    print(sol.maxProfit([7,1,5,3,6,4]))
    print(sol.maxProfit([7,6,4,3,1]))
    print(sol.maxProfit([2,4,1]))
    

if __name__ == ("__main__"):
    main()
