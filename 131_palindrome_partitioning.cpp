/**
    @author [mst]
    @brief  title or quick description
	131_palindrome_partitioning
    Given a string s, partition s such that every substring  of the partition is a palindrome.
    Return all possible palindrome partitioning of s.

    Gains:

    @version 0.1 2023.01
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <string>
using namespace std;

////////////////// DECL_IMPL

// snipped [here]
//
// sub: 41%T 80%S
class Solution {
public:

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
            return false;
        return true;
    }

    void dfs(const string& s, int start, vector<string>&& path, vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(path);
            return;
        }

        for (auto i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, move(path), ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        dfs(s, 0, {}, ans);
        return ans;
    }
};

////////////////// DRIVER
int main()
{
	Solution sol;


    // testing
    string s = "aab";
    vector<vector<string>> res = sol.partition(s);
    cout << s << ": " << endl;



    // string s = "a";
    // cout << s << ": " << endl;



	return 0;
}
