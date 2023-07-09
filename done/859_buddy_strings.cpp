/**
    @author [mst]
    @brief  leetcode series
    859_buddy_strings
	Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
    Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
    For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

    gains:
    -simple indexing

    @version 0.1 2023.04
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <set>
using namespace std;


////////////////// DECL_IMPL


// snipped
// build mismatches vector and check that indexes are swapable
//
// sub 54 52
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // strings must me of same lengths
        if (s.length() != goal.length()) return false;
        // same
        if (s == goal && set<char>(s.begin(), s.end()).size() < s.length())
            return true;

        // detect chars to swap
        vector<int> mismatch;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] != goal[i]) mismatch.push_back(i);

        // positive result if there are exactly two distinct chars and they
        // are replacable by index
        return mismatch.size() == 2
        && s[mismatch[0]] == goal[mismatch[1]]
        && s[mismatch[1]] == goal[mismatch[0]];
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    string str = "ab", goal = "ba";
    cout << s.buddyStrings(str,goal);


    return 0;
}