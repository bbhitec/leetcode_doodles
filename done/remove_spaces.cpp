/**
    @author [mst]
    @file   remove_spaces
    @brief  an algorithm to remove spaces in a string

    gains:
    -cpp strings and char pointers basics

    @version 2024.05
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <string>
#include <algorithm>        // usage of remove_if
#include <cctype>           // usage of isspace
using namespace std;



////////////////// DECL_IMPL

// remove spaces in a string
// simple approach using char pointers to change the string in-place
// O(n) time O(1) space
void remove_spaces(string& s) {
    char *c = &s[0];    // current running pointer
    char *n = c;        // poiter to modified string
                        // [bp] this could be improved with using s.begin()

    while (*c){
        while (*c == ' ')
            c++;    // skip spaces

        if (*c != *n)
            *n = *c;    // copy content to the space-less pointer

        c++;    // advance
        n++;
    }
    s.resize(n - &s[0]);    // cut the rest of the string
                            // [bp] putting an '\0' will not work since the string struct is not necessarily terminated by it
                            // moreover, if it were - it sould be size() - inconsistent
    return;
}

// using cpp built in remove_if and an erasing function
// [wiki] this uses the erase-remove approach:
//  remove_if will modify the values and return a pointer to the end
//  of the modified string. then we use erase to trim the excess
void remove_spaces_builtin(string& s) {
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
}



////////////////// DRIVER
int main()
{
    cout << "[mst] doodle" << endl;

    string s = "This is a   string     with spaces";
    cout << "removing spaces from: " << s << "..." << endl;
    // remove_spaces(s);
    remove_spaces_builtin(s);
    cout << s;

    return 0;
}