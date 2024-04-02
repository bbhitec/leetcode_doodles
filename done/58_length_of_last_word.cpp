/**
    @author [mst]
    @brief  leetcode series
    58_length_of_last_word
    Given a string s consisting of words and spaces, return the length of the last word in the string.
    A word is a maximal substring consisting of non-space characters only.

    gains:
    - basic arrays logic


    @version 2024.04
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL




// run a pointer from the end of the string with conditions to count the word
//
// sub  100 57
class Solution {
public:
    int lengthOfLastWord(string s) {
        int max_len = 0;
        int p = s.length()-1;

        // ignore empty spaces;
        while (s[p] == ' ') p--;

        // count the last word only
        while (p >= 0 && s[p--] != ' ')
            max_len++;

        return max_len;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;
    string str = " ";

    int res = s.lengthOfLastWord(str);
    cout << res;


    return 0;
}