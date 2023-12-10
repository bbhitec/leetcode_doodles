/**
    @author [mst]
    @brief  leetcode series
    867_transpose_matrix
    The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
    Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 105
    -109 <= matrix[i][j] <= 109

    gains:
    -[wip] rd


    @version 0.1 2023.12
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
//
// sub 99 84
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size()));

      for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[0].size(); ++j)
          ans[j][i] = matrix[i][j];

      return ans;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> res = s.transpose(matrix);


    return 0;
}