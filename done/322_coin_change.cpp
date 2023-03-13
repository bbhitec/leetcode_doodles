/**
    @author [mst]
    @brief  leetcode problems series
    322_coin_change
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
    You may assume that you have an infinite number of each kind of coin.

    gains:
    -dynamic programming: botton up solving

    @version 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;

////////////////// DECL_IMPL

// keepa a bottom-up dynamic programming record of the
// minimal composition for each amount up to the desired one.
// referenced: https://www.youtube.com/watch?v=H9bfqozjoqs
//
// sub: 66t 63s
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp struct initted to maximal values
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i < amount+1; i++) {
            // for each amount, compose of the given coins or
            // the value in the dp struct
            for (auto coin : coins) {
                if ((i - coin) >= 0)
                    // recurrence relation
                    dp[i] = min(dp[i],1+dp[i-coin]);
            }
        }
        if (dp[amount] != amount + 1) return dp[amount];
        return -1;
    }
};

////////////////// DRIVER
int main()
{
    Solution sol;
    int amt = 11;
    vector<int> coins = {1,2,5};
    cout << sol.coinChange(coins, amt) << endl;

	return 0;
}
