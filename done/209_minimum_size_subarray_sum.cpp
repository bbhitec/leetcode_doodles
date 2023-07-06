/**
    @author [mst]
    @brief  leetcode series
    209_minimum_size_subarray_sum
    Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

    gains:
    -sliding window with conditions

    Constraints:
    1 <= target <= 10^9
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^4


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// since we are looking for contiguois subarray, we will use a sliding window that will grow/shrink according to the given target sum
//
// sub 70 99
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int min_nums = 1000001;
      int sum = 0;
      int left = 0;
      int right = 0;
      int sz = nums.size();

      for (; right < sz; right++) {
        if (nums[right] >= target) return 1;  // single number target found

        sum += nums[right];

        while (sum >= target) {
          min_nums = min(min_nums, right - left + 1);
          sum -= nums[left];
          left++;
        }

      }

      if (min_nums == 1000001) return 0;
      return min_nums;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> nums = {2,3,1,2,4,3};
    // vector<int> nums = {1,1,1,1,1,1,1,1};
    vector<int> nums = {1,4,4};
    int target = 4;
    int res = s.minSubArrayLen(target,nums);
    cout << res;


    return 0;
}