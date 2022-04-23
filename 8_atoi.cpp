//
// [mst] 8_atoi.cpp
// leetcode problems series
// 
// 8. String to Integer(atoi)
// Implement atoi which converts a string to an integer.
// 
// The function first discards as many whitespace characters as necessary until the first non - whitespace character is found.Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// If the first sequence of non - whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// If no valid conversion could be performed, a zero value is returned.
// 
// Note:
// -Only the space character ' ' is considered a whitespace character.
// - Assume we are dealing with an environment that could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].If the numerical value is out of the range of representable values, INT_MAX(231 − 1) or INT_MIN(−231) is returned.
//
// features, changelog:
// -initial
//
//


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <string>
using namespace std;

////////////////// DECL_IMPL
class Solution {
public:
	int myAtoi(string s) {
		int i = 0;
		long long n = 0;
		bool neg = false;
		bool pos = false;
		char c = s[i];

		while (c){
			
			switch (c) {

			case '-':
				if (neg) return 0; // allow only a single occurance of the minus sign
				if (pos) return 0; // allow only a single occurance of the minus sign
				neg = true;
				break;
			case '+':
				if (pos) return 0; // allow only a single occurance of the plus sign				
				if (n != 0) return n*((neg) ? (-1) : 1); // no plus sign after the number has started
				else if (neg) return 0;
				pos = true;
				break;

			case ' ':
				if (n != 0) {
					return n*((neg) ? (-1) : 1);
				}
				break;

			case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
				n = n * 10 + (c - '0');	// keep building the number
				if (n > INT_MAX){// + (1 * neg))){
					return (neg) ? INT_MIN : INT_MAX;
				}
				break;

			default:
				return n*((neg)?(-1):1);
				break;
			}	// eo switch
			i++;
			c = s[i];	// prepare for next iteration
		}	// eo while

		return n*((neg) ? (-1) : 1);
	}
};

////////////////// DRIVER
int main()
{
	std::cout << "[mst] leetcode 8. atoi" << endl << endl;

	//SolutionLeet sol;
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













	//string str0 = "42";
	//string str1 = "   -42";
	//string str2 = "4193 with words";
	//string str3 = "words and 987";
	//string str4 = "-91283472332";
	//string str5 = "+1";
	//string str6 = "+-12";
	//string str6 = "+-12";
	//
	//cout << "atoi(" << str0 << ")" << "=" << sol.myAtoi(str0) << endl;
	//cout << "atoi(" << str1 << ")" << "=" << sol.myAtoi(str1) << endl;
	//cout << "atoi(" << str2 << ")" << "=" << sol.myAtoi(str2) << endl;
	//cout << "atoi(" << str3 << ")" << "=" << sol.myAtoi(str3) << endl;
	//cout << "atoi(" << str4 << ")" << "=" << sol.myAtoi(str4) << endl;
	//cout << "atoi(" << str5 << ")" << "=" << sol.myAtoi(str5) << endl;
	//cout << "atoi(" << str6 << ")" << "=" << sol.myAtoi(str6) << endl;
	//cout << "atoi(" << str6 << ")" << "=" << sol.myAtoi(str6) << endl;

	// system("pause");    // [mst][demo] this is not portable!!
	std::cin.get(); // pseudo-pause the console
	return 0;
}
