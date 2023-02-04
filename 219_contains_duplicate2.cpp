/**
    @author [mst]
    @brief  leetcode problems series
    219_contains_duplicate2
    Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

    Gains:

    features, changelog:
    -2023.01:	-initial draft

    @version 0.1 2023.01
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>            // usage of console prints
#include <unordered_map>            // usage of console prints


using namespace std;


////////////////// DECL_IMPL

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) return false;

		// a structure to remember encountered numbers:
		// key: number, value: number of times met
		unordered_map <int, vector<int>> vocabulary;

		for (int i = 0 ; i < nums.size(); i++) {
			cout << i << " " ;
			vector<int> tmp;
			tmp.push_back(i);
			vocabulary[nums[i]] = tmp;


			// vocabulary[nums[i]]={i};
			// if (++vocabulary[num] > 1) {
			// 	// once we meet a multiple occurence, we flag it
            //     return true;
            // }
        }

		// [here] print the built vocab

		int sz = vocabulary.size();
		for (int i = 0; i < sz; i ++) {
			cout << vocabulary[i][0] << endl;
		}


		// for (int key : vocabulary.) {
		// 	cout <<  key << endl;
		// }

		// for( const auto& [key, value] : vocabulary )
        // print_key_value(key, value);


		return false;

    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

	vector<int> nums ={1,2,3,1};
	int k = 3;

	bool res = sol.containsNearbyDuplicate(nums,k);
	cout << res << endl;



	// Input: nums = [1,0,1,1], k = 1
	// Output: true
	// Example 3:

	// Input: nums = [1,2,3,1,2,3], k = 2
	// Output: false

	return 0;
}
