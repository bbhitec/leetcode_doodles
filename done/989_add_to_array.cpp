/**
    @author [mst]
    @brief  leetcode problems series
    989_add_to_array
    The array-form of an integer num is an array representing its digits in left to right order.
    For example, for num = 1321, the array form is [1,3,2,1].
    Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

    gains:
    -some cpp iterators goodies
    -dismantling addition

    @version 0.1 2023.02
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <deque>
#include <string>
using namespace std;


////////////////// DECL_IMPL

// simple conditional adding
//
// sub?: 68T 40S
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        deque<int> res;
        int carry = 0;
        int sum = 0;
        int d = 0;
        int num_d = 0;
        bool in_num=true;   // are we iterating over the num(array) digits?

        // [demo] reverse iteration
        auto it = num.rbegin();
        while (in_num || k) {
            d = k%10;   // cut a digit
            k = k/10;   // trim the number
            num_d = (in_num)?*it:0;

            sum = num_d + d + carry;
            carry = sum/10; // deduct the carry

            res.push_front(sum%10); // record resulting digit

            it++;
            if (it == num.rend()) in_num = false;
        }

        // handle leftover carry
        if (carry) res.push_front(1);

        // [demo] return data by means of iterators
        return {res.begin(),res.end()};
    }
};



////////////////// DRIVER
int main()
{
	Solution sol;
    // vector<int> num = {1,2,0,0}; int  k = 34;
    vector<int> num = {6}; int  k = 809;
    // vector<int> num = {0}; int  k = 23;
    // vector<int> num = {9,9,9,9,9,9,9,9,9,9}; int  k = 1;

    cout << "res: " << endl;
    vector<int> res = sol.addToArrayForm(num,k);

    for (auto n : res) cout << n << " ";


	return 0;
}
