/**
    @author [mst] 
    @file   8_atoi.cpp
    @brief  leetcode problems series

	8. String to Integer(atoi)
	Implement atoi which converts a string to a 32-bit signed integer.

	The function first discards as many whitespace characters as necessary until the first non - whitespace character is found.
	Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
	The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
	If the first sequence of non - whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
	If no valid conversion could be performed, a zero value is returned.

	[mst] a problem mostly to emphasize taking care of inputs, not much on algorithmic solution

	Note:
	- Only the space character ' ' is considered a whitespace character
	- Clamp the result integers within the 32 - bit signed integer range : [−2^31, 2^31 − 1]
	- 0 <= s.length <= 200

	features, changelog:
    -2022.04: resubmission: T: 6 ms, faster than 37.32% S: 7 MB, less than 89.92%
    -2021.01: -initial draft

    @author [mst]
    @version 0.2 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <string>

using namespace std;


////////////////// DECL_IMPL

// previous submission. not polished and obsolete
class Solution1 {
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


class Solution {	
public:
	// Implement atoi which converts a string to a 32-bit signed integer.
	int myAtoi(string s) {
		int len 		= s.length();
		int i 			= 0;
		long long res 	= 0;		// initialize the result
		int sign 		= 1;		// result def is positive

		// skip leading whitespaces
		// this stands with the case of an empty string or a spaces only string
		while (s[i] == ' ') {
			i++;
		}

		// handle negative sign (only in the beginning of the number)
		if (s[i] == '-') {
			sign = -1;
			i++;
		} else	// allow only one sign char
		if (s[i] == '+') {
			i++;
		}

		// walk throu the rest of the string,
		// a while(s[i] >= '0' && s[i] <= '9') loop would also work
		while (i < len ) {
			switch (s[i]) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				res = res * 10 + s[i] - '0';

				// trim if INT_MAX overflown
				if (res > INT_MAX) {
					return (1 == sign) ? INT_MAX: INT_MIN;
				}
				break;

			default:
				return res * sign;	// exit loop on any other char
				break;	
			}
			i++;
		}
		
		return res*sign;
	}	// eo: myAtoi
};

////////////////// DRIVER
int main()
{
	std::cout << "[mst] leetcode 8. atoi" << endl << endl;

	Solution1 sol;
	string inputs[] = {
		"42",
		"   -42",
		"4193 with words",
		"words and 987",
		"-91283472332",
		"+1",
		"+-12",
		"00000-42a1234",
		"-+12",
		"21474836460",
		"-5-",
	};

	for (string str : inputs) {
		std::cout << "atoi(" << str << ")" << "=" << sol.myAtoi(str) << endl;
	}

	//std::cin.get(); // pseudo-pause the console
	return 0;
}
