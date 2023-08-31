/**
    @author [mst]
    @brief  leetcode series
    688_knight_probability_in_chessboard
    On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
    A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
    Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
    The knight continues moving until it has made exactly k moves or has moved off the chessboard.
    Return the probability that the knight remains on the board after it has stopped moving.

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


class Solution2 {
public:
    int onBoard = 0;
    bool withinBoundaries (int n, int row, int col) {
      if ((row < 0) || (col < 0) || (row >= n) || (col >= n)) return false;
      return true;
    }

    double knightProbability(int n, int k, int row, int col) {
      if (k < 0) return 0;

      return withinBoundaries(n, row, col) +
      knightProbability (n, k-1, row+1, col+2) +
      knightProbability (n, k-1, row-1, col+2) +
      knightProbability (n, k-1, row+1, col-2) +
      knightProbability (n, k-1, row-1, col-2) +
      knightProbability (n, k-1, row+2, col+1) +
      knightProbability (n, k-1, row-2, col+1) +
      knightProbability (n, k-1, row+2, col-1) +
      knightProbability (n, k-1, row-2, col-1);
    }
};


// snipped reference dp solution
//
// sub 63 34
class Solution
{
  public:
    double knightProbability(int n, int K, int r, int c)
    {
      constexpr double kProb = 0.125; //
      const vector<pair<int, int>> dirs{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

      // dp[i][j] := probability to stand on (i, j)
      vector<vector<double>> dp(n, vector<double>(n));
      dp[r][c] = 1.0;

      for (int k = 0; k < K; ++k)
      {
        vector<vector<double>> newDp(n, vector<double>(n));
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            if (dp[i][j] > 0.0)
            {
              for (const auto &[dx, dy] : dirs)
              {
                const int x = i + dx;
                const int y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= n) // out of bounds
                  continue;
                newDp[x][y] += dp[i][j] * kProb;
              }
            }
        dp = move(newDp);
      }

      return accumulate(dp.begin(), dp.end(), 0.0,
                        [](double s, const vector<double> &row)
                        {
                          return s + accumulate(row.begin(), row.end(), 0.0);
                        });
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    int n = 3, k = 2, row = 0, column = 0;

    vector<int> rods = {1,2,3,6};
    // vector<int> rods = {1,2,3,4,5,6};
    // vector<int> rods = {1,2};
    int res = s.knightProbability(n, k, row, column);
    cout << res;


    return 0;
}