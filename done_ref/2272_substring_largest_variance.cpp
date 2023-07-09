/**
    @author [mst]
    @brief  leetcode series
    2272_substring_largest_variance
    The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
    Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
    A substring is a contiguous sequence of characters within a string.

     gains:
    -[wip] rd solutions
    -[wip] rd kadane algorithm

    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// snipped - walkcc reference
// using Kadane's maximum subarray sums algorithm
// https://en.wikipedia.org/wiki/Maximum_subarray_problem
//
// sub 98 97
class Solution {
 public:
  int largestVariance(string s) {
    int ans = 0;

    // calculate for each two chars
    for (char c1 = 'a'; c1 <= 'z'; ++c1)
      for (char c2 = 'a'; c2 <= 'z'; ++c2)
        if (c1 != c2)
          ans = max(ans, kadane(s, c1, c2));

    return ans;
  }

  // use Kadane's maximum subarray sums algorithm
  int kadane(const string &s, char ch_high_freq, char ch_low_freq)
  {
    int ans = 0;
    int countA = 0;
    int countB = 0;
    bool canExtendPrevB = false;

    for (const char c : s)
    {
      if (c != ch_high_freq && c != ch_low_freq)
        continue;
      if (c == ch_high_freq)
        ++countA;
      else
        ++countB;
      if (countB > 0)
      {
        ans = max(ans, countA - countB);
      }
      else if (countB == 0 && canExtendPrevB)
      {
        ans = max(ans, countA - 1);
      }
      if (countB > countA)
      {
        countA = 0;
        countB = 0;
        canExtendPrevB = true;
      }
    }
    return ans;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    string st = "aababbb";
    int res = s.largestVariance(st);
    cout << res;

    return 0;
}