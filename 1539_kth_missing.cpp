/**
    @author [mst]
    @brief  leetcode series
    1539_kth_missing
	You are given an integer array nums and two integers minK and maxK.
	Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
    Return the kth positive integer that is missing from this array.

    gains:
    -[wip] rd the solution


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 100t 73s
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int first = 0;
        int last = arr.size();

        while(first<last) {
            int middle = first+(last-first)/2;

            if(arr[middle] - middle > k) {
                last=middle;
            } else {
                first = middle +1;
            }
        }

        return last+k;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;


    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    int res = s.findKthPositive(arr,k);
    cout << res;


    return 0;
}