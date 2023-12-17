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
#include <algorithm>
using namespace std;


////////////////// DECL_IMPL


// snipped: reverse the whole string then reverse each word
//
// sub 100 73
class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());       // Reverse the whole string.
    reverseWords(s, s.length());       // Reverse each word.
    return cleanSpaces(s, s.length()); // Clean up the spaces.
  }

private:
  void reverseWords(string &s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (
        i < j || 
        i < n && 
        s[i] == ' ') // Skip the spaces.
        ++i;
      while (
        j < i || 
        j < n && 
        s[j] != ' ') // Skip the spaces.
        ++j;
      reverse(s.begin() + i, s.begin() + j); // Reverse the word.
    }
  }

  // Trim leading, trailing, and middle spaces
  string cleanSpaces(string &s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ') // Skip the spaces.
        ++j;
      while (j < n && s[j] != ' ') // Keep non spaces
        s[i++] = s[j++];
      while (j < n && s[j] == ' ') // Skip the spaces.
        ++j;
      if (j < n) // Keep only one space.
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }
};


// initial: use built-in stringstream and build a new string in reverse
//
// sub 86 23
class Solution2 {
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