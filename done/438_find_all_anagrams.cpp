/**
    @author [mst]
    @brief  leetcode problems series
    438_find_all_anagrams
    Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
	An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

	gains:
	-cpp strings/char manipulations
	-sliding window and histogram compination

    features, changelog:
    -[wip] an option to a string/substring based window solution
    -2023.02:	-initial draft

    @version 0.1 2023.02
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>

using namespace std;


////////////////// DECL_IMPL


// build a sliding window for an anagram check at each index of the target string
// this can be considered an expansion of 242_valid_anagram problem
//
// sub: 42T 77S
class Solution {
private:
	static const int MAX = 256;
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		int p_size = p.length();
		int s_size = s.length();

		// them basic cases
        if (p.empty() || s.empty() || s_size == 0 || p_size > s_size) {
            return res;
        }

        int targetMap[MAX] = {0};
        int currentMap[MAX] = {0};


		// initial map (sub-pattern sized)
        for (int i = 0; i < p_size; i++) {
            targetMap[p[i] - 'a']++;
            currentMap[s[i] - 'a']++;
        }

		// we now define a comparison window...
        int start = 0;
        int end = p_size;

        while(end < s_size) {
            if (isAnagram(currentMap, targetMap)) {
                res.push_back(start);
            }
			// ... and move it as we go
            currentMap[s[start] - 'a']--;
            start++;
            currentMap[s[end] - 'a']++;
            end++;
        }

        // last case
        if (isAnagram(currentMap, targetMap)) {
            res.push_back(start);
        }

        return res;
    }

	// given the preconditions in the calling function, we diet this
	bool isAnagram(int* charMap, int* targetMap) {
        for (int i = 0; i < MAX; i++) {
            if (charMap[i] != targetMap[i]) {
                return false;
            }
        }
        return true;
    }

};

void printVec (vector<int> v) {
	for (auto x : v) cout << x << " ";
}




////////////////// DRIVER
int main()
{
	Solution sol;
	string s = "cbaebabacd", p = "abc";

	vector<int> res = sol.findAnagrams(s,p);
	cout << "res: ";
	printVec(res);
	cout << endl;

	return 0;
}
