/*
[mst] 392_is_subsequence.cpp
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

Gains:
-Hash map histogram uses

features, changelog:
-2022.12: -initial draft
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
using namespace std;


////////////////// DECL_IMPL


// simply traverse a pointer over subsequence and make sure characters appear in the targer string
// note: using counter i and s[i] instead of the pointer yielded 22%S result!
//
// sub: 100%T 98%S
class Solution {
public:
    bool isSubsequence(string s, string t) {
		if (s.empty()) return true; // empty subsequence is true by default
		int sl = s.length();
		if (s.length() > t.length()) return false;

		char *sc = &s[0];

		for (char& tc: t) {
			if ((*sc == tc) && (*sc != '\0')) {
				sc++;
				if (*sc == '\0') return true;	// found subsequence
			}
		}
        return false;
    }
};


// this is more like a substring rather a subsequence...
class Solution0 {
public:
    bool isSubsequence(string s, string t) {
		if (s.empty()) return false;	// halt on empty target
		int sl = s.length();
		if (s.length() > t.length()) return false;

		int i = 0;

		for (char& tc: t) {
			while ((s[i] == tc+i) && (i < sl)) {
				i++;
			}
			if (i == sl) return true;	// found subsequence
			i = 0;
		}
        return false;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

	string s = "abc";
	string t = "ahbgdc";
	cout << "result: " << sol.isSubsequence(s, t) << endl;

	string s2 = "axc";
	string t2 = "ahbgdc";
	cout << "result: " << sol.isSubsequence(s2, t2) << endl;

	string s3 = "";
	string t3 = "ahbgdc";
	cout << "result: " << sol.isSubsequence(s3, t3) << endl;

	return 0;
}
