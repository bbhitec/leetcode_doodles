/**
	@author {mst}
	@brief  leetcode series
	1020_nums_of_enclaves
	You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
	A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
	Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

	gains:
	-orientation with dfs matrix traversion
	-cpp accumulate goodies

	@version 0.1 2023.04
*/

////////////////// LIBS
#include <iostream>		// usage of console prints
#include <vector>
#include <numeric>		// using accumulate
using namespace std;


////////////////// DECL_IMPL


// regular dfs solution: first dfs-nullify border-accessible islands
// then count remaining 1-tiles
//
// sub 76 57
// sub 91 51 (with accumulate)
class Solution {
private:
	int ans;
	int rows;
	int cols;
	void dfs(vector<vector<int>>& grid, int i, int j) {
		// stop on boundary
		if (i < 0 || j < 0 || i > rows-1 || j > cols-1)
			return;

		// stop on illegal tile
		if (grid[i][j] == 0)
			return;

		grid[i][j] = 0;	// dfs action - disablse this tile
		dfs(grid, i+1, j);
		dfs(grid, i, j+1);
		dfs(grid, i-1, j);
		dfs(grid, i, j-1);
		return;
	}

public:
    int numEnclaves(vector<vector<int>>& grid) {
        // ans = 0;
		rows  = grid.size();
		cols  = grid[0].size();

		// first, get rid of a border-adjacent islands using the
		// 200_num_of_islands nullifiecation
		for (auto i = 0; i < rows; i++) {
			for (auto j = 0; j < cols; j++) {
				if (i == 0 || j == 0 || i == rows-1 || j == cols-1) {
					if (grid[i][j] == 1) dfs(grid,i,j);
				}
			}
		}

		// // now that all border-accessible tile were nullified,
		// // we simply count the remaining 1-tiles
		// for (auto i = 0; i < rows; i++) {
		// 	for (auto j = 0; j < cols; j++) {
		// 		if (grid[i][j] == 1) ans++;
		// 	}
		// }

		// this is snipped from elsewhere but its some advanced cpp stuff
		return accumulate(begin(grid), end(grid), 0, [](int s, vector<int>& row) {
			return s + accumulate(begin(row), end(row), 0);
		});

		// return ans;
    }
};

////////////////// DRIVER
int main()
{
	Solution s;

	vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
	cout << s.numEnclaves(grid);
	return 0;
}
