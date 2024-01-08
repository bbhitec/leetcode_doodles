/**
    @author [mst]
    @brief  leetcode series
    2707_extra_chars
    You are given a 0-indexed string s and a dictionary of words dictionary.
    You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary.
    There may be some extra characters in s which are not present in any of the substrings.
    Return the minimum number of extra characters left over if you break up s optimally.

    gains:
    -[wip] run examples
    -rd the soluition


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <unordered_set>
using namespace std;


////////////////// DECL_IMPL


// snipped walkccc
//
// Similar to 139. Word Break
// sub: 57 92 98
class Solution
{
public:
    int minExtraChar(string s, vector<string>& dictionary)
    {
      const int n = s.length();
      const unordered_set<string> dictionarySet{dictionary.begin(),
                                                dictionary.end()};
      // dp[i] := min extra characters if breaking up s[0:i] optimally
      vector<int> dp(n + 1, n);
      dp[0] = 0;

      for (int i = 1; i <= n; ++i)
          for (int j = 0; j < i; ++j)
              // s[j..i) is in dictionarySet.
              if (dictionarySet.count(s.substr(j, i - j)))
                  dp[i] = min(dp[i], dp[j]);
              // s[j..i) are extra characters.
              else
                  dp[i] = min(dp[i], dp[j] + i - j);

      return dp[n];
    }
};

////////////////// DRIVER
int main()
{
    Solution s;


    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    int res = s.findKthPositive(arr,k);
    cout << res;


    return 0;
}