/**
    @author [mst]
    @brief  leetcode series
    1493_longest_subarray_of_ones
    Given a binary array nums, you should delete one element from it.
    Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

    gains:
    -sliding windows with conditions


    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// sliding window approach: count ones between zeroes
//
// sub 47 19
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int ans = 0;
      int zeroes = 0;
      int left = 0, right = 0;  // define window bounds
      int sz = nums.size();

      for (; right < sz; right++) {
        // count zeroes within window
        if (nums[right] == 0)
          zeroes++;

        // resize window according to zeroes encountered
        while (zeroes == 2) {
          if (nums[left] == 0)
            zeroes--;
          left++;
        }
        // window size (plus the implicit 1 zero) is the 1's count
        ans = max(ans, right - left);
      }
      return ans;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> nums = {1,1,0,1};
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    // vector<int> nums = {1,1,1};
    int res = s.longestSubarray(nums);
    cout << res;


    return 0;
}