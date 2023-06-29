/**
    @author [mst]
    @brief  leetcode series
	46_permutations
	Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    gains:
	-backtracking in cpp
	-basic combinatorics


    @version 2023.05
*/


////////////////// LIBS
#include <iostream>				// usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// a backtracking solution:
// at each stage of a given vector: pop the first member,
// permute the rest of the vector and then add the member back to each result
//
// sub
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res = {{}};

		if (nums.size() == 1) {
			return
		}

		for (auto i = 0; i < nums.size(); i++) {
			// pop element
			int n = nums.pop_back();

			// permute the rest
			permute (nums);

			// now add the element 'backtrack it'

		}


		for (auto &n : nums) {

		}

		return res;


    }
};

////////////////// DRIVER
int main()
{
	Solution s;
	vector<int> nums = {1,2,3};
	cout << "solution:" << endl;
	vector<vector<int>> res = s.permute(nums);

	for (vector<int> &vec : res) {
		for (auto &n : vec) {
			cout << n << " ";
		}
		cout << endl;
	}
		cout << endl;


	return 0;
}
