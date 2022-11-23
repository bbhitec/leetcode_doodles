/**
    @author [mst]
    @file   231_power_of_two.cpp    
    @brief  leetcode problems series

    Given an integer n, return true if it is a power of two. Otherwise, return false.
	An integer n is a power of two, if there exists an integer x such that n == 2x.


    Gains:
    -trickery, -algorithmic thinking
	-bitwise operations


    features, changelog:
	-2022.11 a solution using the unordered map
    -2021: -initial draft: naive iteratve solution, O(n^2) time

    @version 0.1 2021
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
using namespace std;

////////////////// DECL_IMPL

class Solution {
public:
	// bitwise solution: 100% time 27% space
    bool isPowerOfTwo(int n) {
		// consider lower cases
		if (n == 0) return false;
		if (n == 1) return true;
		
		// a power of two is a number represented by a single turned on bit
		// reach firsts turned bit
		while ((1 & n) != 1) n = n>>1; 
		return (n ==1); // if there are other 1's, its not a power of 2
    }
};

class Solution2 {
public:
	// a more elegant solution from answers: 19.79% T 27.68% S
	bool isPowerOfTwo(int n) {
		// consider lower cases
		if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};


////////////////// DRIVER
int main()
{
	cout << "[mst] leetcode 231. power of two" << endl << endl;	

	Solution solution;
	Solution2 solution2;
	cout << "isPowerOfTwo(0): " << solution.isPowerOfTwo(0) << endl;
	cout << "isPowerOfTwo(1): " << solution.isPowerOfTwo(1) << endl;
	cout << "isPowerOfTwo(6): " << solution.isPowerOfTwo(6) << endl;
	cout << "isPowerOfTwo(128): " << solution.isPowerOfTwo(128) << endl;
	cout << "isPowerOfTwo(257): " << solution.isPowerOfTwo(257) << endl;
	cout << "isPowerOfTwo(2048): " << solution2.isPowerOfTwo(2048) << endl;
	

	return 0;
}
