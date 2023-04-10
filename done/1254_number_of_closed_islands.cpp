/**
	@author {mst}
	@brief  leetcode series
	1254_number_of_closed_islands
	Given a 2D grid consists of 0s (land) and 1s (water).
	An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
	Return the number of closed islands.

	gains:
	-orientation with dfs matrix traversion
	-using 200_num_of_islands solution as a sub-problem

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
// sub 98 96
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
		if (grid[i][j] == 1)
			return;

		grid[i][j] = 1;	// dfs action - disablse this tile
		dfs(grid, i+1, j);
		dfs(grid, i, j+1);
		dfs(grid, i-1, j);
		dfs(grid, i, j-1);
		return;
	}

public:
    int closedIsland(vector<vector<int>>& grid) {
        ans = 0;
		rows  = grid.size();
		cols  = grid[0].size();

		// first, get rid of a border-adjacent islands using the
		// 200_num_of_islands nullifiecation
		for (auto i = 0; i < rows; i++) {
			for (auto j = 0; j < cols; j++) {
				if (i == 0 || j == 0 || i == rows-1 || j == cols-1) {
					if (grid[i][j] == 0) dfs(grid,i,j);
				}
			}
		}

		// now that irrelevant islands have been removed,
		// run 200_num_of_islands solution
		for (auto i = 0; i < rows; i++) {
			for (auto j = 0; j < cols; j++) {
				if (grid[i][j] == 0) {
					dfs(grid,i,j);
					ans++;
				}
			}
		}
		return ans;
    }
};

////////////////// DRIVER
int main()
{
	Solution s;

	vector<vector<int>> grid = {
		{1,1,1,1,1,1,1},
     	{1,0,0,0,0,0,1},
     	{1,0,1,1,1,0,1},
     	{1,0,1,0,1,0,1},
     	{1,0,1,1,1,0,1},
     	{1,0,0,0,0,0,1},
     	{1,1,1,1,1,1,1}};

	cout << s.closedIsland(grid);
	return 0;
}
