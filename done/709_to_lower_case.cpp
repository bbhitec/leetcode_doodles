/**
    @author [mst]
    @file   709_to_lower_case.cpp
    709. To Lower Case
    Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

    Gains:
    -ASCII basics

    @version 0.1 2022.12
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <string>
using namespace std;


////////////////// DECL_IMPL


// simple ASCII modification
//
// sub: 100%T 81%S
class Solution {
public:
    string toLowerCase(string s) {
        int i = 0;

        int to_lower = 'a' - 'A';

        for (char c : s) {
            if (('A' <= c) && (c <= 'Z')) {
                s[i] = c + to_lower;
            }
            i++;
        }

        return s;
    }
};




////////////////// DRIVER
int main()
{

    Solution sol1;

    string test = "PiTAs";
    cout << sol1.toLowerCase(test) << endl;;

	return 0;
}
