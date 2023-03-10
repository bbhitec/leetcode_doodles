/**
    @author [mst]
    @brief  leetcode problems series
    283_move_zeroes
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
	Note that you must do this in-place without making a copy of the array.

    gains:
	-basic pointer/array operations in cpp

    @version 2023.02
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>            // usage of console prints

using namespace std;


////////////////// DECL_IMPL

// straightforward padding with thow pointers
//
// sub: 92t 65s
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
		if (sz == 0) return;
		int c=0;

		// owerwrite zeroes
		for(int i=0; i<sz; i++) {
			if (nums[i] != 0) {
				nums[c] = nums[i];
				c++;
			}
		}

		// pad the rest of vector with zeroes
		while (c < sz) {
			nums[c] = 0;
			c++;
		}
		return;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

	vector<int> nums ={0,1,0,3,12};
	cout << "before:" << endl;
	for (const auto& n : nums) cout << n << " ";
	sol.moveZeroes(nums);
	cout << endl << "after:" << endl;
	for (const auto& n : nums) cout << n << " ";

	return 0;
}
