/**
    @author [mst]
    @brief  leetcode series
    1464_max_product2
    Given the array of integers nums, you will choose
    two different indices i and j of that array.
    Return the maximum value of (nums[i]-1)*(nums[j]-1).

    Constraints:
    2 <= nums.length <= 500
    1 <= nums[i] <= 10^3

    gains:
    -wip


    @version 0.1 2023.12.12
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>
#include <ranges>
#include <iterator>
using namespace std;


////////////////// DECL_IMPL

// using built in sort algo
//
// sub 52 97
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        return (nums[0]-1) * (nums[1]-1);   // size > 2 is given
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> nums = {3,4,5,2};
    cout << s.maxProduct(nums);


    return 0;
}