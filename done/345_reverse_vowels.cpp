/**
    @author [mst]
    @brief  leetcode series
    345_reverse_vowels
    Given a string s, reverse only all the vowels in the string and return it.
    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

    gains:
    -string manipulation
    -test cases


    @version 0.1 2023.11
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL

// assisted
// run a pointer from each end and swap vowels when met
//
// sub 68, 80
class Solution {
public:
    // this is fast but not case-friendly
    bool is_vowel(char v) {
      return (0x208222>>(v&0x1f))&1;
    }

    string reverseVowels(string s) {
      // init fast vowel checker array
      bool is_vowel[CHAR_MAX] = { false };
      is_vowel['A'] = true;
      is_vowel['a'] = true;
      is_vowel['E'] = true;
      is_vowel['e'] = true;
      is_vowel['U'] = true;
      is_vowel['u'] = true;
      is_vowel['I'] = true;
      is_vowel['i'] = true;
      is_vowel['O'] = true;
      is_vowel['o'] = true;

      int len = s.length();
      int i = 0;
      int j = len-1;

      while ( i<j ) {
        // locate next vowels
        while (i < j && !is_vowel[s[i]])
          ++i;
        while (i < j && !is_vowel[s[j]])
          --j;

        // swap vowels
        swap(s[i++], s[j--]);
      }
      return s;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    cout << (s.reverseVowels("hello")) << endl;
    cout << (s.reverseVowels("leetcode")) << endl;
    cout << (s.reverseVowels(" ")) << endl;
    cout << (s.reverseVowels("Egad! Loretta has Adams as mad as a hatter. Old age!")) << endl;


    return 0;
}