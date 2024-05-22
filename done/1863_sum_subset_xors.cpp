/**
    @author [mst]
    @brief  leetcode series
    1863_sum_subset_xors
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums.

    Note: Subsets with the same elements should be counted multiple times.
    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

    gains:
    -back-tracing, recursion
    -xor basics


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

// naive recursive: we back-track the numbers and in each recursion either include the current number, or not
// this will be O(2^n)
// partially assisted
//
// sub 68 83
class Solution1 {
private:
    // we use this helper method to present our own index-enabled prototype
    int rec(vector<int>& nums, int i, int sum) {
      if (i == nums.size())
        return sum;

      int a = rec(nums, i+1, sum);  // don't include current number
      int b = rec(nums, i+1, sum ^ nums[i]); // include current number
      return a+b; // total summation
    }
public:
    int subsetXORSum(vector<int>& nums) {
      return rec(nums, 0, 0);
    }
};


// math based approach: looking at the bit wise representation, the nature of a xor will have 2^(n-1) bits active if at least one of the numbers has that bit
// thus, we logical-or all the bits on 'nums' (we only care if there is at least one bit turned on) and count the bits appearance (2^n-1 for each turned bit, or the sum << (n-1)
// assisted
//
// sub 100 88
class Solution2 {
public:
    int subsetXORSum(vector<int>& nums) {
      int res = 0;
      for (auto& x: nums) res |= x;
      return res << nums.size() - 1;
    }
};

// same as the math version but using c++20 accumulate
//
// sub 100 88
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
      return accumulate(nums.begin(), nums.end(), 0, bit_or<>()) << nums.size() - 1;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> nums = {10, 6};
    int res = s.subsetXORSum(nums);
    cout << res;


    return 0;
}