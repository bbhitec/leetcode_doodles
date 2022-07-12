/**
    @author [mst]
    @file   6_zigzag.cpp
    @brief  leetcode doodles

    The string "PAYPALISHIRING" is written in a zigzag pattern on a given
    number of rows like this: (you may want to display this pattern in a fixed
    font for better legibility)
    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a
    number of rows:

    string convert(string s, int numRows);

    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000
    

    features, changelog:
    -2021.04:	-initial draft
				[wip][here] indicate optional miscompletion

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <string> // for string class

using namespace std;

////////////////// DECL_IMPL
class Solution {
public:
    string convert(string s, int numRows) {    
        string res;

        return res;    
    }
};


////////////////// DRIVER
int main()
{
    cout << "[mst] leetcode 6_zigzag.cpp doodle" << '\n' << '\n';

    Solution sol1;
    int numRows = 0;

    // Example 2:
    // Input: s = "PAYPALISHIRING", numRows = 3
    // Output: "PAHNAPLSIIGYIR"
    string s1 = "PAYPALISHIRING";
    numRows = 3;
    cout << "string: " << s1 << " zigzagged " << numRows << " lines: "  << '\n';
    cout << sol1.convert(s1, numRows)  << '\n';



    // Example 2:
    // Input: s = "PAYPALISHIRING", numRows = 4
    // Output: "PINALSIGYAHRPI"
    // Explanation:
    // P     I    N
    // A   L S  I G
    // Y A   H R
    // P     I

    /*string s2 = "PAYPALISHIRING";
    numRows = 4;
    cout << "string: " << s2 << " zigzagged " << numRows << " lines: "  << '\n';
    cout << sol1.convert(s2, numRows)  << '\n';*/

	return 0;
}
