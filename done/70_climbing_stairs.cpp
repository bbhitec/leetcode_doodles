/*
[mst] 205_isomorphic_strings.cpp
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Gains:
-Hash map mapping

features, changelog:
-2022.12: -initial draft
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
using namespace std;

#include <vector>
#include <unordered_map>

////////////////// DECL_IMPL


// memoized dynamic programming solution: record every calculated number as we go
// there was some issue with initializing:
//   vector<int> memo(n+1,0);
//
// sub: 100T 44S
class Solution {
public:
    int climbStairs(int n) {
		vector<int> memo;

		memo.push_back(0);	// member 0 is a dummy
		memo.push_back(1);
		memo.push_back(2);

        for (int i = 3; i<=n; i++)
			memo.push_back( memo[i-1] + memo[i-2]);

        return memo[n];
    }
};

////////////////// DRIVER
int main()
{
	Solution sol;
	cout << "result: " << sol.climbStairs(1) << endl;

	return 0;
}
