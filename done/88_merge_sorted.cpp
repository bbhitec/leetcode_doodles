/**
    @author [mst]
    @brief  leetcode series
    88_merge_sorted
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.
    The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    gains:
    -great array indexing logic excersize


    @version 2024.05
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL

// refresher 2024.05
// use end-to-beginning indexing and the constraints that num1 is n+m sized to include the result set
// assisted
// time O(n+m) space O(1)
//
// sub 100 99
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;  // num1 index
        int j = n-1;  // num2 index
        int k = m+n-1;  // merged index

        while (j>=0) {
          if (i>=0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            k--;
            i--;
          }
          else {
            nums1[k] = nums2[j];
            k--;
            j--;
          }
        }
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> nums1 = {1,2,3,0,0,0};
    // int m = 3;
    // vector<int> nums2 = {2,5,6};
    // int n = 3;

    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;

    // string res = s.reverseWords("Let's take LeetCode contest");
    s.merge(nums1,m,nums2,n);
    for (auto& n: nums1) cout << n << ", ";



    return 0;
}