/**
    @author [mst]
    @brief  leetcode series
    200_num_of_islands
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    gains:
    -traversing in a table
	-bfs/dfs matrix traversal
	-[wip] rd the bfs solution


    @version 0.1 2023.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// regular dfs solution - solved in cpp a short while after a python solution
//
// sub 98 65
class Solution {
private:
	int ans;
	int rows;
	int cols;
	void dfs (vector<vector<char>>& grid, int i, int j) {
		// stop on boundary
		if (i < 0 || j < 0 || i > rows-1 || j > cols-1)
			return;

		// stop on illegal tile
		if (grid[i][j] == '0')
			return;

		grid[i][j] = '0';	// dfs action - disablse this tile
		dfs(grid, i+1, j);
		dfs(grid, i, j+1);
		dfs(grid, i-1, j);
		dfs(grid, i, j-1);
		return;
	}
public:
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
		rows  = grid.size();
		cols  = grid[0].size();

		for (auto i = 0; i < rows; i++)
			for (auto j = 0; j < cols; j++) {
				if (grid[i][j] == '1') {
					dfs(grid,i,j);
					ans++;
				}
			}

		return ans;
    }
};

////////////////// DRIVER
int main()
{
	Solution s;

	// vector<vector<char>> grid = {
	// 	{'1','1','1','1','0'},
  	// 	{'1','1','0','1','0'},
  	// 	{'1','1','0','0','0'},
  	// 	{'0','0','0','0','0'}};

	vector<vector<char>> grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}};

	cout << s.numIslands(grid);
	return 0;
}
