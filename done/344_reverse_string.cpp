/**
    @author [mst]
    @brief  leetcode problems series
    344_reverse_string
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.

    gains:
    -basic pointer operation

    @version 0.1 2023.02

*/

////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <algorithm>
using namespace std;

////////////////// DECL_IMPL

// pointer at each end going towards center, swapping chars
//
// sub: 60T 50S
class Solution {
public:
    void reverseString(vector<char>& s) {
        int range = s.size()/2;
        int start = 0, end = s.size()-1;

        char tmp;
        while (start < end) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;

            start++;
            end--;
        }

    }
};


////////////////// DRIVER
int main()
{

    Solution sol1;

    vector<char> s = {'h','e','l','l','o'};
    for_each(s.begin(),s.end(), [](auto &x){cout << " " << x;});

    sol1.reverseString(s);
    cout << endl << "after" << endl;
    for_each(s.begin(),s.end(), [](auto &x){cout << " " << x;});


	return 0;
}
