/**
    @author [mst]
    @brief  leetcode series
    2864_max_odd_binary_number
    You are given a binary string s that contains at least one '1'.
    You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
    Return a string representing the maximum odd binary number that can be created from the given combination.
    Note that the resulting string can have leading zeros.

    gains:
    -cpp strings and stringstreams
    -ranges and string initiations
    -binary and math basics

    @version 2024.03
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <sstream>      // building strings dynamically
#include <algorithm>    // counting chars in string
using namespace std;


////////////////// DECL_IMPL

// count ones and construct a new string
// assisted
//
// sub 100 19
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = ranges::count(s,'1');
        int zeroes = s.length() - ones;
        return string(ones-1, '1') + string(zeroes, '0') + '1';
    }
};

// naive: count all 1's and build the result string by putting all ones as msbs, while keeping one for the lsb
//
// sub 77 10
class Solution2 {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length();
        if (len == 1) return "1";

        // int i = std::stoi(s, nullptr, 2);
        int count = 0;
        for (auto c : s) if (c == '1') count++;

        stringstream ss;
        for (int i=0; i< len-1; i++) {
            ss << (count-- > 1) ? "1" : "0";
        }
        ss << "1";

        return ss.str();
    }
};

////////////////// DRIVER
int main()
{
    Solution sol;

    string s = "01011";
    string res = sol.maximumOddBinaryNumber(s);
    cout << res;

    return 0;
}