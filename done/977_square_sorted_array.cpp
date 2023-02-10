/**
    @author [mst]
    @brief  leetcode problems series
    977_square_sorted_array
    Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    gains:
    -simple python array manipulation
    -built in sorting, iterators
    -basic lambda functions
    -cpp for_each

    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <algorithm>
using namespace std;

////////////////// DECL_IMPL


// sub 44T 17S
class Solution0 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums)
            res.push_back(n*n);

        sort(res.begin(), res.end());

        return res;
    }
};

// same as above but with [demo] lambda
//
// sub: without saving iterators: 82T 33S
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // adding these yielded: sub 55T 95S
        auto bgn = nums.begin();
        auto end = nums.end();

        for_each(bgn,end,[](int &x){x*=x;});
        sort(bgn,end);
        return nums;
    }
};


////////////////// DRIVER
int main()
{

    Solution sol1;
    vector<int> nums1 = {-4,-1,0,3,10};
    vector<int> res = sol1.sortedSquares(nums1);

    // [demo] vector print one liner
    for_each(res.begin(),res.end(), [](int &x){cout << " " << x;});
    // for (auto n : res)
    //     cout << " " << n;

	return 0;
}
