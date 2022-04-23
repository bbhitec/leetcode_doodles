//
// [mst] 8_atoii.cpp
// leetcode problems series
//
// implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
// The algorithm for myAtoi(string s) is as follows:
// 1. Read in and ignore any leading whitespace.
// 2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// 3. Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
// 4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// 5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// 6. Return the integer as the final result.
// Note:
// -Only the space character ' ' is considered a whitespace character.
// -Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
//

#include <iostream>            // usage of console prints
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	int myAtoi(string s) {
		int len = s.length();
		int i = 0;
		int res = 0;
		int sign = 1;

		// skip leading whitespaces
		// this stands with the case of an empty string or a spaces only string
		while (s[i] == ' ') {
			i++;
		}

		// handle sign signs
		if (s[i] == '-') {
			sign = -1;
			i++;
		}
		if (s[i] == '+') {
			i++;
		}

		while (i < len ) {	// watch that end of string
			switch (s[i]) {
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				//cout << "char: " << s[i] << " res: " << res << endl;
				res = res * 10 + s[i] - '0';
				//cout << "char: " << s[i] << " res: " << res << endl;

			default:
				break;	// exit loop on any other char
			}
			i++;
		}

		res *= sign;
		return res;
	}	// eo: myAtoi
};



int main()
{
	cout << "[mst] 8. atoi solution" << endl << endl;
	// Solution sol;
	// string str = "   -12";
	// int n = sol.myAtoi(str);
	// cout << "test string: " << str << " myAtoi: " << n << endl;

	Solution sol;
	string strs[] = {
		"42",
		"   -42",
		"4193 with words",
		"words and 987",
		"-91283472332",
		"+1",
		"+-12",
		"00000-42a1234" };

	for (string str : strs) {
		std::cout << "atoi(" << str << ")" << "=" << sol.myAtoi(str) << endl;
	}

	//cin.get(); // pseudo-pause the console
	return 0;
}