/**
    @author [mst]
    @brief  leetcode problems series
    67_add_binary
    Given two binary strings a and b, return their sum as a binary string.

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.

    gains:
	-cpp strings and bitwise operations

    @version 0.1 2023.02
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <string>
using namespace std;


////////////////// DECL_IMPL

// sub: 67T 86S
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int i_a = a.size()-1;
        int i_b = b.size()-1;

        int carry = 0;
        int sum = 0;
        int d_a = 0;
        int d_b = 0;
        while (i_a >= 0 || i_b >= 0) {
            d_a = (i_a>=0)?(a[i_a] - '0'):0;
            d_b = (i_b>=0)?(b[i_b] - '0'):0;
            sum = (d_a + d_b + carry);
            carry = sum/2;

            res.insert(0, to_string(sum%2));

            i_a--;
            i_b--;
        }

        // handle leftovers
        if (carry) res.insert(0, "1");

        return res;
    }
};



////////////////// DRIVER
int main()
{
	Solution sol;
    // string a="11", b="1";
    string a="1010", b="11010";

    cout << "Binary add: " << a << "+" << b << "=" << sol.addBinary(a,b) << endl;

	return 0;
}
