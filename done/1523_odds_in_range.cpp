/**
    @author [mst]
    @brief  leetcode problems series
    1523_odds_in_range
    Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

    gains:
    -math thinking
    -sum bountdaries

    @version 0.1 2023.02

*/

////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <algorithm>
using namespace std;

////////////////// DECL_IMPL

// pointer at each end going towards center, swapping chars
//
// sub: 100T7S
class Solution {
public:
    int countOdds(int low, int high) {
        int res = 0;
        int diff = high - low;

        if (low%2) {
            diff--;
            res++;
        }

        if (high%2) {
            diff--;
            res++;
        }

        return res+(diff/2);

    }
};


////////////////// DRIVER
int main()
{
    Solution sol;

    int low = 798273637, high = 970699661;
    int res = sol.countOdds(low,high);

    cout << "res: " << res << endl;

	return 0;
}
