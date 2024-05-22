/**
    @author [mst]
    @file   remove_spaces
    @brief  an algorithm to remove spaces in a string

    gains:
    -cpp strings and char pointers basics

    @version 2024.05
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <string>
using namespace std;



////////////////// DECL_IMPL

// remove spaces in a string
// simple approach using char pointers to change the string in-place
// O(n) time O(1) space
void remove_spaces(string& s) {
    char *c = &s[0];    // current running pointer
    char *n = c;        // poiter to modified string

    while (*c){
        while (*c == ' ')
            c++;    // skip spaces

        if (*c != *n)
            *n = *c;    // copy content to the space-less pointer

        c++;    // advance
        n++;
    }
    *n = '\0';  // cut the rest of the string
    return;
}



////////////////// DRIVER
int main()
{
    cout << "[mst] doodle" << endl;

    string s = "This is a string with spaces";
    cout << "removing spaces from: " << s << "..." << endl;
    remove_spaces(s);
    cout << s;

    return 0;
}