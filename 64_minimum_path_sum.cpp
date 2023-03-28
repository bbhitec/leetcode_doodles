/**
    @author [mst]
    @brief  leetcode series
    64_minimum_path_sum
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
    Note: You can only move either down or right at any point in time.

    gains:
    -[wip]


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 57 92 98
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i > 0 && j > 0)
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        else if (i > 0)
          grid[i][0] += grid[i - 1][0];
        else if (j > 0)
          grid[0][j] += grid[0][j - 1];

    return grid[m - 1][n - 1];
  }
};

////////////////// DRIVER
int main()
{
    Solution s;


    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    int res = s.findKthPositive(arr,k);
    cout << res;


    return 0;
}