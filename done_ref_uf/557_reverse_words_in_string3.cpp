/**
    @author [mst]
    @brief  leetcode series
    557_reverse_words_in_string3
    Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    gains:
    -simple cpp string manipulation


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL

// snipped
// run pointers between white spaces, reversing relevant string portions
//
// sub 56, 55
class Solution {
public:
  string reverseWords(string s)  {
    int i = 0;
    int j = 0;

    while (i < s.length()) {
      while (i < j || i < s.length() && s[i] == ' ')
        ++i;
      while (j < i || j < s.length() && s[j] != ' ')
        ++j;
      reverse(s.begin() + i, s.begin() + j);
    }

    return s;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    string res = s.reverseWords("Let's take LeetCode contest");
    cout << res;


    return 0;
}