/**
    @author [mst]
    @file   26_remove_duplicates.cpp
    @brief  leetcode problems series

    26. Remove Duplicates from Sorted Array
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
    template for new files creation. Return k after placing the final result in the first k slots of nums.

    Gains:
    -pointers control
    -cpp STL :)

    features, changelog:
    -2021.05.09:	-initial draft. STL's unique method: 62.98% time, 36.87% space
                    -snipped iterative: 67.86% time, 75.01% space

    @version 0.1 2022.05
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <algorithm>

using namespace std;
////////////////// DECL_IMPL

// helper vec printer
void print_vec(vector<int> v) {
    for (const auto& member : v) {		// [demo] using 'auto' for type inference and a more generic approach
            std::cout << member << ", ";
        }
        std::cout << endl;
}

// snipped iterative solution: run a helper 'cur' pointer that wil make sure to
// advance and update in-place only unique members
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int cur=1;
        for(int i=1;i<a.size();i++){
            if(a[i]!=a[i-1]){
                a[cur]=a[i];
                cur++;
            }
        }
        return cur;
    }
};

// a solution using the stl unique method. its like cheating
class SolutionUnique {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator ip;

        ip = std::unique(nums.begin(), nums.end());
        int sz = std::distance(nums.begin(), ip);
        nums.resize(sz);
        return sz;
    }

};



////////////////// DRIVER
int main()
{
	cout << "[mst] 26_remove_duplicates leetcode doodle" << '\n' << '\n';

    SolutionUnique sol2;
    vector<int> result{0,0,1,1,1,2,2,3,3,4};
    cout << "Example 1:" << endl;
    print_vec(result);
    sol2.removeDuplicates(result);
    print_vec(result);

    Solution sol1;
    //vector<int> result2{0,0,1,1,1,2,2,3,3,4};
    vector<int> result2{1,1};
    cout << "Example 1:" << endl;
    print_vec(result2);
    cout << sol1.removeDuplicates(result2) << endl;
    print_vec(result2);

	return 0;
}
