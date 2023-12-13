/**
    @author [mst]
    @brief  leetcode series
    1582_special_positions_in_matrix
    Given an m x n binary matrix mat, return the number of special positions in mat.
    A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

    gains:
    -basic arrays operations


    @version 0.1 2023.12.13
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// snipped
//
// sub: 68 46
class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        int ans = 0;
        vector<int> rowOnes(m);
        vector<int> colOnes(n);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1) {
                    ++rowOnes[i];
                    ++colOnes[j];
                }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 1 && rowOnes[i] == 1 && colOnes[j] == 1)
                    ++ans;

        return ans;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    vector<vector<int>> mat1=  {{1,0,0},{0,0,1},{1,0,0}};
    vector<vector<int>> mat2=  {{1,0,0},{0,1,0},{0,0,1}};
    cout << s.numSpecial(mat1) << endl;
    cout << s.numSpecial(mat2) << endl;

    return 0;
}