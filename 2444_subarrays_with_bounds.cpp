/**
    @author [mst]
    @brief  leetcode series
    2444_subarrays_with_bounds
	You are given an integer array nums and two integers minK and maxK.
	A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
	The minimum value in the subarray is equal to minK.
	The maximum value in the subarray is equal to maxK.
	Return the number of fixed-bound subarrays.
	A subarray is a contiguous part of an array.

    gains:


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

class Solution
{
public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK)
	{
		long long ans = 0;
		int j = -1;
		int prevMinKIndex = -1;
		int prevMaxKIndex = -1;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] < minK || nums[i] > maxK)
				j = i;
			if (nums[i] == minK)
				prevMinKIndex = i;
			if (nums[i] == maxK)
				prevMaxKIndex = i;
			// any index k in [j + 1, min(prevMinKIndex, prevMaxKIndex)] can be the
			// start of the subarray s.t. nums[k..i] satisfies the conditions
			ans += max(0, min(prevMinKIndex, prevMaxKIndex) - j);
		}

		return ans;
	}
};

////////////////// DRIVER
int main()
{
	Solution s;
	vector<int> nums = {1,3,5,2,7,5}; int minK = 1, maxK = 5;
	// vector<int> nums = {1,1,1,1}; int minK = 1, maxK = 1;

	cout << s.countSubarrays(nums, minK, maxK);
	return 0;
}
