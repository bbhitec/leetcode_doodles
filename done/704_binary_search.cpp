/**
    @author [mst]
    @brief  leetcode series
	704. Binary Search
    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
    You must write an algorithm with O(log n) runtime complexity.

    Constraints:
    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.

    gains:
    -binary search algo in cpp


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// the regular binary boundary-disection solution
//
// sub 82 17
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        // consider constraint: 1 <= nums.length <= 10^4
        if (sz == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }

        int left = 0;
        int right = sz-1;
        int mid;
        while (left <= right) {
            mid = (left + right)/2;
            if (nums[mid] == target) return mid;

            // update boundaries
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> nums = {-1,0,3,5,9,12};
    // int target = 9;
    int target = 2;
    int res = s.search(nums,target);
    cout << res;


    return 0;
}