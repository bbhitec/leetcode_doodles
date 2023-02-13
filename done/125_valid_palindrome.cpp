/**
    @author [mst]
    @brief  leetcode problems series
	125_valid_palindrome
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
	Given a string s, return true if it is a palindrome, or false otherwise.

    gains:


    @version 2023.02
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <string>
#include <algorithm>    // usage of string reverse
using namespace std;

////////////////// DECL_IMPL

// walk over a string once, building a formatted lower-case version, the check if the result is a palindrome
// sub: 26T 22S
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string formatted;
        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(islower(ch) || isdigit(ch) || isupper(ch)) formatted+= tolower(ch);
        }

        string reversed = formatted;
        reverse(reversed.begin(),reversed.end());

        return (formatted==reversed);
    }
};



// approuch from both edges, check conditions
// this yielded some weird errors on a " " at leetcode
//
class Solution0 {
private:
    bool isAlpha(char c) {
        cout << "checking: " << c << endl;
        return ((('a'<=c)&&('z'>=c)) || (('A'<=c)&&('Z'>=c)));
    }
public:
    bool isPalindrome(string s) {
        // approach from both ends
        int l = 0;
        int r = s.size()-1;
        cout << isAlpha(s[r])<< endl;

        do {
            // skip non alphanumericals
            // while (!std::isalpha(s[l])) l++;
            // while (!std::isalpha(s[r])) r--;
            while (!isAlpha(s[l])) l++;
            while (!isAlpha(s[r])) r--;
            char cl = s[l];
            char cr = s[r];

            if (std::tolower(cl) != std::tolower(cr)) return false;

        } while (l++ < r--);

        return true;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;
	// string s = "m ama m";
	string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    // string s = " ";
    // string s = "0P";

	bool ok = sol.isPalindrome(s);
	cout << "the string: " << s << " is" << ((ok)?" ":" not ") << "a palindrome" << endl << endl;

	return 0;
}
