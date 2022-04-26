/**
    @author [mst]
    @file   518_coin_change2.cpp    
    @brief  leetcode problems series

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

    Constraints:
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000

    Gains:
    - dynamic programming: recursion an memoization
    - cpp dynamic allocation
    - algorithm: counting all possible unique combinations


    features, changelog:
    -2022.04.25: unoptimized solution, grabbed an answer from discussions
    -2022.04: -initial draft

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
#define DEBUG 0

////////////////// DECL_IMPL


// [mst] my initial solution: recursion with a structure to track unique solutions
// was disqualified for bad performance :( needs memoization [wip]
class Solution2 {
private:
    set<vector<int>> solutions;
    vector<int> trace;
    int sol_count = 0;

    int combinations_checkup(int amount, vector<int>& coins) {
        if (amount == 0) {
            if (DEBUG) {
                cout << "solution found! " << endl;
                for (auto coins : trace) {
                cout << coins << " " ;
                }
            }
            sort( trace.begin(), trace.end() );            
            if(solutions.insert(trace).second) {
                sol_count ++;
                return 0;   // report a found uniquely composed solution
            }
            if (DEBUG) cout << endl;
        }
        if (amount < 0) {
            if (DEBUG) cout << "dead end at: " << amount << endl;
            return 0;
        }

        for (auto i : coins) {
            if (DEBUG) cout << "amnt:" << amount << " exploring: " << i <<", " << endl;
            trace.push_back(i);
            combinations_checkup(amount-i, coins);
            trace.pop_back();
        }

        return 0;
    }

public:
    int change(int amount, vector<int>& coins) {
        combinations_checkup(amount, coins);

        return sol_count;        
    }
};

// solution snipped from the discussion section: recursion with memoization
class Solution {
public:
    int res = 0;
    int coins_msize = 301;
    int amounts = 501;
    int** dp;
    //int dp[301][501];   // memoization record
                        // [demo] some cpp compilers don't allow oversized
                        // arrays, so we allocate dynamically

    int solve( vector<int>& coins , int amt , int i) {
        if(i<0 || amt < 0){return 0;}
        if(amt == 0){return 1;}
        if(dp[i][amt] != -1 ){return dp[i][amt];}
        
        return dp[i][amt] = solve(coins , amt-coins[i] , i) + solve(coins , amt , i-1);
    }

    int change(int amount, vector<int>& coins) {
        
        // prep the memoization record        
        dp = new int*[coins_msize];
        // [here] do a proper initialization
        // [wip] make the last example work
        for (int i = 0; i < coins_msize; i++) {
            dp[i] = new int[amounts]();
            memset(dp[i] , -1 , coins_msize*sizeof(dp[i])/2);

        }
        
        int n = coins.size();
        
        res = solve(coins , amount , n-1);

        // for (int i = 0; i < coins_msize; i++) {
        //     for (int j = 0; j < amounts; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }            
        //     cout << endl;

        // }

        // manually clean up [bp] this is generally inadvisable
        for (int i = 0; i < coins_msize; i++) {
            delete[] dp[i];
        }
        delete[] dp;

        return res; 

    }
};


////////////////// DRIVER
int main()
{    
	cout << "[mst] 518_coin_change2" << endl;
    //Solution2 sol1;
    Solution sol1;
/*
    // Example 1:
    // Input: amount = 5, coins = [1,2,5]
    // Output: 4
    // Explanation: there are four ways to make up the amount:
    // 5=5
    // 5=2+2+1
    // 5=2+1+1+1
    // 5=1+1+1+1+1    
    int amt = 5;
    vector<int> coins = {1,2,5};
    cout << "Input: amount = 5, coins = [1,2,5]. Sol: " << sol1.change(amt,coins) << endl;


    // Example 2:
    // Input: amount = 3, coins = [2]
    // Output: 0
    // Explanation: the amount of 3 cannot be made up just with coins of 2.
    int amt2 = 3;
    vector<int> coins2 = {2};
    cout << "Input: amount = 3, coins = [2]. Sol: " << sol1.change(amt2,coins2) << endl;


    // Example 3:
    // Input: amount = 10, coins = [10]
    // Output: 1
    int amt3 = 10;
    vector<int> coins3 = {10};
    cout << "Input: amount = 10, coins = [10]. Sol: " << sol1.change(amt3,coins3) << endl;
*/

    // // Example 4:
    // 500
    // [1,2,5]
    int amt3 = 500;
    vector<int> coins3 = {1,2,5};
    cout << "Input: amount = 500, coins = [1,2,5]. Sol: " << sol1.change(amt3,coins3) << endl;

	//cin.get(); // pseudo-pause the console
	return 0;
}
