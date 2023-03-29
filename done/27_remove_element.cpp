/**
    @author [mst]
    @brief  leetcode series
    27_remove_element
	Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
    Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
    Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
    Return k.

    gains:
    -basic arrat work in cpp


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <algorithm>        // min_element
#include <numeric>          // accumulate
using namespace std;


////////////////// DECL_IMPL

// idea: run a separate pointer that will point to the next valid spot in the
// given array and will write in that spot only valid values from the regular pointer
// sub 58 75
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        // for (auto &n : nums) cout << n << " ";
        // cout << endl;

        return (k);
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> nums = {3,2,2,3}; int val = 3;
    vector<int> nums = {0,1,2,2,3,0,4,2}; int val = 2;

    int res = s.removeElement(nums,val);
    cout << res;


    return 0;
}