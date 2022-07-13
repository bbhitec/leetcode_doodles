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
    -2021.07:	-initial draft
				-21.96% time, 14.02% space solution

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream> // usage of console prints
#include <string>   // for string class
#include <vector>   // imitate a stack

using namespace std;

////////////////// DECL_IMPL

// [mst ]initial naive solution: build a numRows sized stack and put each char
// to the relevant stack. then pop in order
//  Runtime: 50 ms, faster than 21.96% of C++ online submissions for Zigzag Conversion.
//  Memory Usage: 19.4 MB, less than 14.02% of C++ online submissions for Zigzag Conversion.
//
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;   

        vector<vector<char>> stack1{};
        for (int i=0;i<numRows;i++){
            vector<char> row_vec;
            stack1.push_back(row_vec);
        }
        string res;
        int st = 0;
        int dir = 1;

        // separate to zigzag rows
        for (char c : s) {
            stack1[st].push_back(c);
            if ((st+dir) > (numRows-1)) dir = -1;
            else if ((st+dir) < 0) dir = 1;
            st+= dir;
            // cout << c;
        }

        // reconstruct result from the 'stacks'
        for (vector<char> row : stack1) {
            for (char ch : row) res += ch;
        }
        return res;    
    }
};

// official leetcode solution (same idea)
class Solution1 {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};


////////////////// DRIVER
int main()
{
    cout << "[mst] leetcode 6_zigzag.cpp doodle" << '\n' << '\n';

    Solution sol1;
    int numRows = 0;

    // Example 0:
    // Input: s = "PAYPALISHIRING", numRows = 3
    // Output: "PAHNAPLSIIGYIR"
    string s0 = "AB";
    numRows = 1;
    cout << "string: " << s0 << " zigzagged " << numRows << " lines: "  << '\n';
    cout << sol1.convert(s0, numRows)  << '\n';

/*
    // Example 1:
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

    string s2 = "PAYPALISHIRING";
    numRows = 4;
    cout << "string: " << s2 << " zigzagged " << numRows << " lines: "  << '\n';
    cout << sol1.convert(s2, numRows)  << '\n';
*/
	return 0;
}
