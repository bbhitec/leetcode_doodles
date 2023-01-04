/**
    @author [mst]
    @brief  leetcode problems series
    944_delete_columns.cpp
    You are given an array of n strings strs, all of the same length.
    The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:
    Return the number of columns that you will delete.

    Gains:
    -basic array orientation

    features, changelog:
    -2023.01:	-initial draft

    @version 0.1 2023.01
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <string>
#include <vector>

using namespace std;



////////////////// DECL_IMPL

// simply check each str[i] vertically across all given strings
//
// sub: 19%T 95%S
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int num_of_strings = strs.size();
        int len = strs[0].size();
        // cout << "len: "<<len<<endl;

        int bad_cols = 0;

        for (int i=0; i<len; i++) {
            for (int j=0; j<num_of_strings-1; j++) {
                if (strs[j][i] > strs[j+1][i]) {
                    bad_cols++;
                    break;
                }
            }
        }
        return bad_cols;
    }
};

////////////////// DRIVER
int main()
{
    using namespace std;

    Solution sol;

    vector<string> strs = {"cba","daf","ghi"};
    cout << "result: " << sol.minDeletionSize(strs) << endl;

	return 0;
}
