/**
    @author [mst]
    @brief  leetcode series
    2966_divide_array_max_difference
    medium
    You are given an integer array nums of size n and a positive integer k.
    Divide the array into one or more arrays of size 3 satisfying the following conditions:
        Each element of nums should be in exactly one array.
    The difference between any two elements in one array is less than or equal to k.
    Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

    gains:
    -[wip] rd sol
    -greedy approach


    @version 2024.02
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>
using namespace std;


////////////////// DECL_IMPL

// sort the array and check in every three numbers. that the difference is kept
// assisted
//
// sub 98 61
class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 2; i < nums.size(); i += 3) {
      if (nums[i] - nums[i - 2] > k)
        return {};
      ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
    }

    return ans;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;

    vector<vector<int>> res = s.divideArray(nums, k);


    return 0;
}