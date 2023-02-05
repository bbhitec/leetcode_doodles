/**
    @author [mst]
    @brief  leetcode problems series
    242_valid_anagram
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

	gains:
    -cpp string and char handling
    -histogram mapping and checking

    features, changelog:
    -2023.02:	-initial draft

    @version 0.1 2023.02
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>

using namespace std;


////////////////// DECL_IMPL


// build occurence histograms/maps for the given strings and compare the results
//
// sub: 95T 85S
class Solution {
private:
    // safe case ASCII chars limit
	static const int MAX = 256;
public:
    bool isAnagram(string s, string t) {
        int s_size = s.length();

        // basic cases
        if (s_size != t.length()) {
            return false;
        }

        // map occurences (we presume only valid ASCII chars are given)
        int sMap[MAX] = {0};
        int tMap[MAX] = {0};
        for (int i = 0; i < s_size; i++) {
            sMap[s[i] - 'a']++;
            tMap[t[i] - 'a']++;
        }

        // compare histogram maps
        for (int i = 0; i < MAX; i++)
            if (tMap[i] != sMap[i]) return false;

        return true;
    }
};



////////////////// DRIVER
int main()
{
	Solution sol;

	// string s = "anagram", t = "nagaram";
    string s = "a", t = "ab";


	cout << "res: " << sol.isAnagram(s,t) << endl;

	return 0;
}
