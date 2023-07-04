/**
    @author [mst]
    @brief  leetcode series
    137_single_number2
    Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
    You must implement a solution with a linear runtime complexity and use only constant extra space.

    constraints:
    1 <= nums.length <= 3 * 104
    -231 <= nums[i] <= 231 - 1
    Each element in nums appears exactly three times except for one element which appears once.


    gains:
    -bit fields and sums manipulation


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL


// paritally referenced:
// https://youtu.be/cOFAmaMBVps
// Sum all numbers' bits at each position and check if divisible by 3 (meaning the bit appeared in three-counted numbers) if not - the odd number has the bit turned on
//
// sub: 84 98
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int ans = 0;

      // go through each of 32 bits
      for (int bit = 0; bit < 32; bit++) {
        int sum = 0;
        for (auto num : nums) {
          sum += (num >> bit) & 1;
        }
        ans |= (sum%3) << bit;  // turn on this bit for the answer
      }
      return ans;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> nums = {2,2,3,2};
    vector<int> nums = {0,1,0,1,0,1,99};
    int res = s.singleNumber(nums);
    cout << res;


    return 0;
}