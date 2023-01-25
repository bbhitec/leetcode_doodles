/**
    @author [mst]
    @brief  leetcode problems series
    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer.

    Constraints:
    -1 <= s.length <= 15
    -s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    -It is guaranteed that s is a valid roman numeral in the range [1, 3999].


    Gains:
    -STL unordered map usage, strings/char and iterators refresher


    features, changelog:
    -2021.04:	-initial solution 74%T, 46%S

    @version 0.1 2022.11
*/

////////////////// LIBS
#include <iostream>            // usage of console prints
#include <string>
#include <unordered_map>


////////////////// DECL_IMPL

class Solution {
public:
    // initial approach: iterate through the string adding numbers.
    // have a 1 forward lookahead to spot substraction cases
    int romanToInt(std::string s) {

        // store translation data in a hash map. we don't need an
        // ordered one since we won't iterate over it
        std::unordered_map<char, int> map{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int sum = 0;
        int curr = 0;
        int next = 0;

        std::string::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            curr = map[*it];
            next = 0;
            if (it+1 != s.end()){
                // consider lookahead, if not end of string
                next = map[*(it+1)];
            }

            // [mst] after browsing solutions, we can simply substract from sum and not the next char
            if (curr < next) {
                sum += (next-curr);
                it++;
            }
            else {
                sum += curr;
            }
        }

        return sum;
    }
};


////////////////// DRIVER
int main()
{
    using namespace std;
	cout << "[mst] 13. Roman to Integer doodle" << '\n' << '\n';

    Solution sol1;

    // test case 1
    string s1 = "XXVII";
    cout << sol1.romanToInt(s1) << '\n';

    // test case 2
    string s2 = "LVIII";
    cout << sol1.romanToInt(s2) << '\n';

    // test case 3
    string s3 = "MCMXCIV";
    cout << sol1.romanToInt(s3) << '\n';



	cin.get(); // pseudo-pause the console
	return 0;
}
