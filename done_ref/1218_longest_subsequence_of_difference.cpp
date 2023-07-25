/**
    @author [mst]
    @brief  leetcode series
    1218_longest_subsequence_of_difference
    Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
    A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

    gains:
    -[wip] rd solution


    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <unordered_map>
using namespace std;


////////////////// DECL_IMPL



// snipped
//
// sub 87 68
class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int ans = 0;
    unordered_map<int, int> lengths;

    for (int num : arr) {
      if (auto it = lengths.find(num - difference); it != lengths.cend())
        lengths[num] = it->second + 1;
      else
        lengths[num] = 1;
      ans = max(ans, lengths[num]);
    }
    return ans;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> arr = {1,2,3,4};
    // int difference = 1;
    vector<int> arr = {1,5,7,8,5,3,4,2,1};
    int difference = -2;
    int res = s.longestSubsequence(arr,difference);
    cout << res;


    return 0;
}