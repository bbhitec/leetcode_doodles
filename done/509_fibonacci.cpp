/*
[mst] 509_fibo_memonacci.cpp
The fibo_memonacci numbers, commonly denoted F(n) form a sequence, called the fibo_memonacci sequence,
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).


Gains:
-basic recursion
-basic dynamic programming solution

features, changelog:
-2022.12: -initial draft
		  -recursive solution submission
*/ 


////////////////// LIBS
#include <iostream>            // usage of console prints
using namespace std;


////////////////// DECL_IMPL

// simple recursive solution'
//
// sub: 34%T 79%S
// same solution in py3: 27$T 96%S, with lru_cache: 31%T 55%S
class Solution0 {
public:
    int fib(int n){
        if (n == 0) return 0;
        if (n == 1) return 1;

        return fib(n-1) + fib(n-2);
    }
};

// dynamic programming approach
//
// sub: 100%T 15%S
class Solution {
public:
    // find an n-th fibonacci number using dynamic programming approach:
    int fib(int n) {
        // keep note of previously calculated numbers (memoization)
        // extra 2 slots for the basic cases
        int fibo_memo[n+2];

        // define basic cases
        fibo_memo[0] = 0;
        fibo_memo[1] = 1;

        // run a 'pseudo' recursion while memoizing all calculated values
        for (int i = 2; i <= n; i++) {
            fibo_memo[i] = fibo_memo[i-1] + fibo_memo[i-2];
        }

        return fibo_memo[n];    // we have the required value        
    }
};



////////////////// DRIVER
int main()
{
	Solution sol;
	cout << "result: " << sol.fib(7);

	cin.get(); // pseudo-pause the console
	return 0;
}
