/**
    @author [mst]
    @brief  leetcode series
    1071_gcd_str
    For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
    Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

    gains:
    -[wip] rd solutions
    -[wip] run


    @version 0.1 2023.08.31
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL

class Solution
{
public:
  string gcdOfStrings(string str1, string str2)
  {
    if (str1.length() < str2.length())
      return gcdOfStrings(str2, str1);
    if (str1.find(str2) == string::npos)
      return "";
    if (str2.empty())
      return str1;
    return gcdOfStrings(str2, mod(str1, str2));
  }

private:
  string mod(string &s1, const string &s2)
  {
    while (s1.find(s2) == 0)
      s1 = s1.substr(s2.length());
    return s1;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    int n = 3, k = 2, row = 0, column = 0;

    vector<int> rods = {1,2,3,6};
    // vector<int> rods = {1,2,3,4,5,6};
    // vector<int> rods = {1,2};
    int res = s.knightProbability(n, k, row, column);
    cout << res;


    return 0;
}