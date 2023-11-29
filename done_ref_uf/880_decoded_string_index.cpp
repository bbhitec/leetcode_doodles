/**
    @author [mst]
    @brief  leetcode series
    880_decoded_string_index
    You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
    If the character read is a letter, that letter is written onto the tape.
    If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
    Given an integer k, return the kth letter (1-indexed) in the decoded string.

    gains:
    -[wip] rd solutions
    -[wip] accumulate and inits


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
//
// sub 100, 9
class Solution
{
public:
  string decodeAtIndex(string s, int k)
  {
    long size = 0; // Length of decoded `s`

    for (const char c : s)
      if (isdigit(c))
        size *= c - '0';
      else
        ++size;

    for (int i = s.length() - 1; i >= 0; --i)
    {
      k %= size;
      if (k == 0 && isalpha(s[i]))
        return string(1, s[i]);
      if (isdigit(s[i]))
        size /= s[i] - '0';
      else
        --size;
    }

    return nullptr;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    string res = s.decodeAtIndex("leet2code3",10);
    cout << res;


    return 0;
}