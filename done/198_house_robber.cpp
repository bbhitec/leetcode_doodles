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

// hold two dp variables:
// one for the score of robbing current house and the ones after the neighbor and
// one for the score of not robbing current house but all from the adjacent
// the current score is the max of the above
//
// sub 100 97
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
