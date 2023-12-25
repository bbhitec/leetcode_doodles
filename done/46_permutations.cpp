/**
    @author [mst]
    @brief  leetcode series
	46_permutations
	Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    gains:
	-backtracking in cpp
	-combinatorics
	-navigating a recursion


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
// partially snipped
//
// sub 100 31 (2023.12)
class Solution {
private:
	vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
		res.clear();

		vector<int> permutation = {};
		vector<bool> used(nums.size());

		dfs (nums, permutation, used);
		return res;
	}

	void dfs (vector<int>& nums, vector<int>& permutation, vector<bool>& used) {

		// desired permutation length reached
		if (permutation.size() == nums.size()) {
			res.push_back(permutation);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i]) {
				continue;
			}

			// use element
			used[i] = true;
			permutation.push_back(nums[i]);

			// permute
			dfs(nums, permutation, used);

			// unuse element
			used[i] = false;
			permutation.pop_back();
		}

	}
};


void printVecVec (vector<vector<int>>& res) {
	for (vector<int> &vec : res) {
		for (auto &n : vec) cout << n << " ";
		cout << endl;
	}
	cout << endl;
}

////////////////// DRIVER
int main()
{
	Solution s;
	vector<int> nums = {1,2,3};
	cout << "solution:" << endl;
	vector<vector<int>> res = s.permute(nums);

	printVecVec(res);

	return 0;
}
