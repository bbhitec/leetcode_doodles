/**
[mst] 9_palindrome.cpp
leetcode problems series

	9. Palindrome Number
	Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
	Follow up: Could you solve it without converting the integer to a string?

Gains:
-cpp simple string manipulation
-algorithmic: concatenating numbers, reversing a number


features, changelog:

    @author [mst]
    @version 0.1
*/

////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <string>
using namespace std;

////////////////// DECL_IMPL

// converting to vector and comparing from edges
//
// sub: 9T 7S :(
class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0) return true;
		if (x < 0) return false;

		vector<int> vec;

		while (x) {
			vec.push_back(x%10);
			x/=10;
		}

		// // test print
		// for (auto d : vec) cout << d << ", ";

		int l = 0;
		int r = vec.size()-1;

		while (l<r) if (vec[l++] != vec[r--]) return false;

		return true;
	}
};

class Solution0 {
public:
	bool isPalindrome(int x) {
		if (x == 0) return true;
		if (x < 0) return false;
		string s = std::to_string(x);

		int left = 0;
		int right = s.length() - 1;

		// run a pointer from both ends comparing throughout
		while (left < right) {
			if (s.at(left) != s.at(right)) {
				cout << "mismatch at index " << left << " (\"" << s.at(left) << "\")"  << endl;
				return false;
			}
			left++;
			right--;
		}

		return true;
	}
};

// a solution given by leetcode
class SolutionLeet {
public:
	bool isPalindrome(int x) {
		// Special cases:
		// As discussed above, when x < 0, x is not a palindrome.
		// Also if the last digit of the number is 0, in order to be a palindrome,
		// the first digit of the number also needs to be 0.
		// Only 0 satisfies this property.
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
		// For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
		// since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
		return x == revertedNumber || x == revertedNumber / 10;
	}
};


////////////////// DRIVER
int main()
{
	cout << "[mst] leetcode 9. palindrome problem" << endl << endl;

	Solution sol;
	int x = 13231;

	bool ok = sol.isPalindrome(x);
	cout << "the number: " << x << " is" << ((ok)?" ":" not ") << "a palindrome" << endl << endl;

	return 0;
}
