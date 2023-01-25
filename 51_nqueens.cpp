//
// [mst] 51_nqueens.cpp
// leetcode problems series
// 51. N - Queens
// The n - queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n - queens puzzle.
// Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
// 1 <= n <= 9
//
// Example 1:
// Input: n = 4
// 	 Output : [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
// 	 Explanation : There exist two distinct solutions to the 4 - queens puzzle as shown above
// 	 Example 2 :
// 	 Input : n = 1
// 	 Output : [["Q"]]
//
// features, changelog:
// -2021.01: -initial draft
//           -follow up to a stuck progress in python
//


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>

using namespace std;		// just for ease of use

////////////////// DECL_IMPL

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> solutions;


		return solutions;
	}
};

////////////////// DRIVER
int main()
{
	cout << "[mst] 51. nqueens solution" << endl << endl;

	Solution sol;

	cin.get(); // pseudo-pause the console
	return 0;
}