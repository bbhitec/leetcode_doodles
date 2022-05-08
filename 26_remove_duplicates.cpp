/**
    @author [mst]
    @file   26_remove_duplicates.cpp    
    @brief  title or quick description
    26. Remove Duplicates from Sorted Array

    full/optional description: this is a placeholder
    template for new files creation

    features, changelog:
    -2021.04:	-initial draft
				[wip][here] indicate optional miscompletion

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>

using namespace std;    
////////////////// DECL_IMPL

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int dupes = 0;
        // for (const auto& member : nums) {		// [demo] using 'auto' for type inference and a more generic approach
        //     if (member == ) {
        //         member = 
        //     }
        // 	std::cout << member << ", ";
	    // }  
        for (int i = 0; i< nums.size(); i++){
            while (nums[i] == nums[i+dupes+1]) {
                dupes++;    // found a duplicate


            }
            k++;
        }
        return k;
    }
    
};

////////////////// DRIVER
int main()
{
	cout << "[mst] 26_remove_duplicates leetcode doodle" << '\n' << '\n';

    Solution sol1;
    vector<int> result{0,0,1,1,1,2,2,3,3,4};
    sol1.removeDuplicates(result);


	//cin.get(); // pseudo-pause the console
	return 0;
}
