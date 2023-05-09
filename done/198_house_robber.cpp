/**
    @author [mst]
    @brief  leetcode series
	198_house_robber
	You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
	Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    gains:
	-basic dp in cpp

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
    int rob(vector<int>& nums) {
		int with_last = 0;
		int without_last = 0;
		int tmp = 0;

		for (auto n: nums){
			tmp = max(n+ without_last, with_last);
			without_last = with_last;
			with_last = tmp;
		}

		return with_last;

    }
};

////////////////// DRIVER
int main()
{
	Solution s;
	vector<int> nums = {1,2,3,1};
	cout << "solution: " << s.rob(nums) << endl;

	return 0;
}
