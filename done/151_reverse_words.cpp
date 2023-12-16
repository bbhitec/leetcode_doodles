/**
  @author [mst]
  @brief  leetcode series
  151_reverse_words
  Given an input string s, reverse the order of the words.
  A word is defined as a sequence of non-space characters.
  The words in s will be separated by at least one space.
  Return a string of the words in reverse order concatenated by a single space.

  gains:
  -


  @version 2023.12
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <sstream>      // splitting strings
using namespace std;


////////////////// DECL_IMPL

// initial: use built-in stringstream and build a new string in reverse
//
// sub 86 23
class Solution {
public:
  string reverseWords(string s) {
    stringstream ss(s);
    string res;
    ss >> res;

    string word;
    while (ss >> word) {
        // res = word + ((res != "")?" ":"") + res;
        res = word + " " + res;
    }
    return res;
  }
};

////////////////// DRIVER
int main()
{
  Solution s;

  cout << s.reverseWords("the sky is blue");  cout << endl;
  cout << s.reverseWords("  hello world  ");  cout << endl;
  cout << s.reverseWords("a good   example"); cout << endl;

  return 0;
}