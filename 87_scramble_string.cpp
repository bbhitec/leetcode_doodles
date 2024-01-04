/**
    @author [mst]
    @brief  leetcode series
    87_scramble_string
	We can scramble a string s to get a string t using the following algorithm:
    If the length of the string is 1, stop.
    If the length of the string is > 1, do the following:
    Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
    Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
    Apply step 1 recursively on each of the two substrings x and y.
    Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

    gains:
    -[wip] rd the solution


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <algorithm>        // any_of
#include <unordered_map>    // hash map
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 77 64
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        if (s1.length() != s2.length())
            return false;
        const string hashedKey = s1 + '+' + s2;
        if (const auto it = memo.find(hashedKey); it != cend(memo))
            return it->second;

        vector<int> count(128);

        for (int i = 0; i < s1.length(); ++i)
        {
            ++count[s1[i]];
            --count[s2[i]];
        }

        if (any_of(begin(count), end(count), [](int c)
                   { return c != 0; }))
            return memo[hashedKey] = false;

        for (int i = 1; i < s1.length(); ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return memo[hashedKey] = true;
            if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
                return memo[hashedKey] = true;
        }

        return memo[hashedKey] = false;
    }

private:
    unordered_map<string, bool> memo;
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> time = {1,2,3};
    int totalTrips = 5;
    int res = s.minimumTime(time,totalTrips);
    cout << res;


    return 0;
}