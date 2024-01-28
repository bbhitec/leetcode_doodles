/**
    @author [mst]
    @brief  leetcode series
    subsets

    Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    gains:
    -simple cpp sting manipulation


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

// snipped
// run pointers between white spaces, reversing relevant string portions
//
// sub 56, 55
class Solution {
public:
  vector<vector<int>> subSets(vector<int> arr)  {
    vector<vector<int>> res;

    return res;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> arr = {1,2,3,4};

    auto res = s.subSets(arr);


    return 0;
}