/**
    @author [mst]
    @brief  leetcode problems series
    1137_threebonacci
    The Tribonacci sequence Tn is defined as follows:
	T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
	Given n, return the value of Tn.

    features, changelog:
    -2023.01:	-initial draft

    @version 0.1 2023.01
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>            // usage of console prints
#include <unordered_map>            // usage of console prints


using namespace std;


////////////////// DECL_IMPL


// naive recursive solution
// sub: yields runtime exceeded exception, needs dp
class Solution {
public:
    vector<int> memo = {};
    int tribonacci(int n) {
        if (0 == n) return 0;
        if (1 == n) return 1;
        if (2 == n) return 1;

        return (
            tribonacci(n - 1) +
            tribonacci(n - 2) +
            tribonacci(n - 3)
        );

    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

	cout << sol.tribonacci(25) << endl;




	return 0;
}
