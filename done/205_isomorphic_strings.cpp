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

// hold a hash table to map each char to each other, if conflict occured, flag it
// 1 <= s.length <= 5 * 104
// t.length == s.length
//
// sub: 59%T 18%S
class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.empty()) return false;
		int l = s.length();
		if (l == 1) return true;

		// hold mappings from s to t and a back-check
		unordered_map <char, char> vocabulary;
		unordered_map <char, char> reverse;

		for (int i = 0; i < l; i++) {
			if ((vocabulary.find(s[i]) == vocabulary.end()) && (reverse.find(t[i]) == reverse.end())) {
				// new key: map it
				vocabulary[s[i]] = t[i];
				reverse[t[i]] = s[i];
			}
			else {
				if ((vocabulary[s[i]] != t[i]) || (reverse[t[i]] != s[i])) return false;
			}
		}
		return true;
	}
};

// snipped clean community solution
class Solution {
public:
    public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};


////////////////// DRIVER
int main()
{

	Solution sol;

	// string s = "badc";
	// string t = "baba";

	string s = "add";
	string t = "egg";

	cout << "result: " << sol.isIsomorphic(s,t) << endl;


	return 0;
}
