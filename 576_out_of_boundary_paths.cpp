/**
    @author [mst]
    @brief  leetcode series
    576_out_of_boundary_paths
    There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
    Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

    gains:
    -simple cpp sting manipulation


    @version 0.1 2024.01
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL


// recursive pathfinding and adding method with memoization
//
// sub: limit exceeded
class Solution {
  public:
      int mod = 1000000007;
      int rec (int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> memo) {
        // edge reached
        if (startColumn < 0 || startColumn ==n || startRow < 0 || startRow == m)
          return 1;

        // out of moves
        if (maxMove == 0)
          return 0;

        // step in possible directions
        if (memo[maxMove][startRow][startColumn] != -1)
          return memo[maxMove][startRow][startColumn];
        return memo[maxMove][startRow][startColumn] = (
          rec(m,n, maxMove-1, startRow, startColumn + 1, memo) * 1LL +
          rec(m,n, maxMove-1, startRow, startColumn - 1, memo) +
          rec(m,n, maxMove-1, startRow + 1, startColumn, memo) +
          rec(m,n, maxMove-1, startRow - 1, startColumn, memo)
        ) % mod;
      }

      int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));

        return rec (m, n, maxMove, startRow, startColumn, memo);
      }
};


// recursive pathfinding and adding method
//
// sub: limit exceeded
class Solution1 {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

      // edge reached
      if (startColumn < 0 || startColumn ==n || startRow < 0 || startRow == m) {
        return 1;
      }

      // out of moves
      if (maxMove == 0)
        return 0;

      int paths = 0;

      // step in possible directions
      if (startColumn < n) paths += findPaths(m,n, maxMove-1, startRow, startColumn + 1);
      if (startColumn >= 0) paths += findPaths(m,n, maxMove-1, startRow, startColumn - 1);
      if (startRow < m) paths += findPaths(m,n, maxMove-1, startRow + 1, startColumn);
      if (startRow >= 0) paths += findPaths(m,n, maxMove-1, startRow - 1, startColumn);

      return paths;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // cout << s.findPaths(2,2,2,0,0) << endl;
    // cout << s.findPaths(1,3,3,0,1) << endl;
    cout << s.findPaths(8,4,10,5,0) << endl;



    return 0;
}