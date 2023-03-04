/**
    @author [mst]
    @brief  leetcode series
    28_str_first_occurence
	Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack

    gains:
    -basic double-pointer traversal cpp


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// basic double-pointer traversal
// partially snipped
//
// sub: 100t 29s
class Solution {
public:
    int strStr(string haystack, string needle) {
		int h_sz = haystack.size();
		int n_sz = needle.size();
        if (h_sz < n_sz) return -1;

		int j;
		for (int i = 0; i <= h_sz-n_sz; i++) {
			for ( j = 0; j < n_sz; j++) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == n_sz) {
                return i;
            }
		}
		return -1;
    }
};


////////////////// DRIVER
int main()
{
	Solution s;
	// string haystack = "asadbutsad", needle = "sad";
	string haystack = "a", needle = "a";

	cout << s.strStr(haystack,needle);
	return 0;
}
