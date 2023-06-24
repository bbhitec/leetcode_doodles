/**
    @author [mst]
    @brief  leetcode series
    956_tallest_billboard
    You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
    You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
    Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

    gains:
    -[wip] rd solutions
    -[wip] accumulate and inits


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL



// snipped
// recursive dp solution: memoizing maximal possible height for each height difference at each index
//
// sub: 61 79
class Solution1 {
private:
    static const int MAX_SUM = 5001;
    int dp[21][MAX_SUM * 2];   // consider dynamic allocation
    int recurse (vector<int> &rods, int idx, int diff) {
        // finishing condition: went through all rods in this sub tree
        if (idx == rods.size()) return diff == 0 ? 0 : -1e4; // minimal value

        // check memo
        int n_diff = diff + MAX_SUM;  // avoid negative index
        if (dp[idx][n_diff] != -1) return dp[idx][n_diff];

        // recurse into:

        // include this rod in next path
        int v1 = rods[idx] + recurse(rods, idx + 1, diff + rods[idx]);
        // exclude this rod in next path
        int v2 =  recurse(rods, idx + 1, diff - rods[idx]);
        // disregard current rod
        int v3 =  recurse(rods, idx + 1, diff);

        // memoize result
        return dp[idx][n_diff] = max({v1,v2,v3});
    }

public:
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        return recurse(rods, 0, 0);
    }
};

// walkcc reference
//
//
// sub 66 64
class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    const int n = rods.size();
    const int sum = accumulate(rods.begin(), rods.end(), 0);
    // dp[i][j] := max min-height of using rods[0..i) to pile two piles that
    // Have height difference j
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));    // [demo] init a 2d vector
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      const int h = rods[i - 1];
      for (int j = 0; j <= sum - h; ++j) {
        if (dp[i - 1][j] < 0)
          continue;
        // don't use rods[i - 1]
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        // Put on the taller pile
        dp[i][j + h] = max(dp[i][j + h], dp[i - 1][j]);
        // Put on the shorter pile
        dp[i][abs(j - h)] = max(dp[i][abs(j - h)], dp[i - 1][j] + min(j, h));
      }
    }

    return dp[n][0];
  }
};


////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> rods = {1,2,3,6};
    // vector<int> rods = {1,2,3,4,5,6};
    // vector<int> rods = {1,2};
    int res = s.tallestBillboard(rods);
    cout << res;


    return 0;
}