/**
    @author [mst]
    @brief  leetcode series
    2149_rearrange_array_elements
    You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
    You should rearrange the elements of nums such that the modified array follows the given conditions:
    Every consecutive pair of integers have opposite signs.
    For all integers with the same sign, the order in which they were present in nums is preserved.
    The rearranged array begins with a positive integer.
    Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

    Constraints:
    2 <= nums.length <= 2 * 105
    nums.length is even
    1 <= |nums[i]| <= 105
    nums consists of equal number of positive and negative integers.

    gains:
    -algo thinking
    -array manipulation


    @version 2024.02
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL

// approach: save given numbers to a positive and a negative numbers stacks, and then pop the values interchangabily to form the correct result
// the nature of the stacks will keep the desired order.
// assisted
//
// sub 75 5
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        vector<int> positives;
        vector<int> negatives;

        // arrange into separate vectors O(n)
        for (auto n:nums) {
            if (n >= 0) positives.push_back(n);
            else negatives.push_back(n);
        }

        // rebuild into the result O(n)
        for (int i = 0; i < positives.size(); i++) {
            result.push_back(positives[i]);
            result.push_back(negatives[i]);
        }

        return result;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> nums = {3,1,-2,-5,2,-4};
    // vector<int> nums = {1,-1};

    vector<int> res = s.rearrangeArray(nums);
    for (auto n : res ) cout << n << ", ";


    return 0;
}