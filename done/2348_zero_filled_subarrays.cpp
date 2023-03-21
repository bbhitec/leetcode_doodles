/**
    @author [mst]
    @brief  leetcode series
    2348_zero_filled_subarrays
    Given an integer array nums, return the number of subarrays filled with 0.
    A subarray is a contiguous non-empty sequence of elements within an array.

    gains:
    -algo thinking cpp


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 34 14
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int indexBeforeZero = -1;   // last non-zero member

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i])
                indexBeforeZero = i;
            else
                ans += i - indexBeforeZero; // add any following zeroes variations

        return ans;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> arr = {1,3,0,0,2,0,0,4};
    int res = s.zeroFilledSubarray(arr);
    cout << res;
    return 0;
}