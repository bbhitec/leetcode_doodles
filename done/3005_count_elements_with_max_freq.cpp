/**
    @author [mst]
    @brief  leetcode series
    3005_count_elements_with_max_freq
    You are given an array nums consisting of positive integers.
    Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
    The frequency of an element is the number of occurrences of that element in the array.

    gains:
    -basic array operation
    -basic math and histogramming


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

// naive: run and build a numbers histogram noting the max frequency, then accumulate all the max frequency appearances
//
// sub 100 22
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> hist(101);
        int max_hist = 0;

        for (auto &n : nums) {
          hist[n]++;
          if (hist[n] > max_hist) max_hist = hist[n];
        }

        int accum = 0;
        for (auto &b : hist) {
          if (b == max_hist) accum+= max_hist;
        }

        return accum;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> nums = {1,2,2,3,1,4};
    vector<int> nums = {81,81,81,81,81,81,81,17,28,81,81,56,81,54,81,81,81,81,81,60,81,28,81,81,81,81,81,54,81,81,81,81,100,28};
    cout << s.maxFrequencyElements(nums);

    return 0;
}