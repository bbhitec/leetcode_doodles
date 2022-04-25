/**
    @author [mst]
    @file   518_coin_change2.cpp    
    @brief  leetcode problems series

    <full/optional description: this is a placeholder
    template for new files creation>

    Constraints:
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000


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

class Solution {
public:
    int dp[301][5001];

    int solve( vector<int>& coins , int amt , int i)
    {
        if(i<0 || amt < 0){return 0;}
        if(amt == 0){return 1;}
        if(dp[i][amt] != -1 ){return dp[i][amt];}
        
        return dp[i][amt] = solve(coins , amt-coins[i] , i) + solve(coins , amt , i-1);
    }

    int change(int amount, vector<int>& coins) {
        memset(dp , -1 , sizeof(dp));
        int n = coins.size();
        return solve(coins , amount , n-1);   
    }
};


////////////////// DRIVER
int main()
{    
	cout << "[mst] 518_coin_change2" << endl;
    Solution2 sol1;

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
    cout << "Input: amount = 5, coins = [1,2,5]. Sol: " << sol1.change(amt,coins);

/*
    // Example 2:
    // Input: amount = 3, coins = [2]
    // Output: 0
    // Explanation: the amount of 3 cannot be made up just with coins of 2.
    int amt2 = 3;
    vector<int> coins2 = {2};
    cout << "Input: amount = 3, coins = [2]. Sol: " << sol1.change(amt2,coins2);


    // Example 3:
    // Input: amount = 10, coins = [10]
    // Output: 1
    int amt3 = 10;
    vector<int> coins3 = {10};
    cout << "Input: amount = 10, coins = [10]. Sol: " << sol1.change(amt3,coins3);


    // // Example 4:
    // 500
    // [1,2,5]
    int amt3 = 500;
    vector<int> coins3 = {1,2,5};
    cout << "Input: amount = 500, coins = [1,2,5]. Sol: " << sol1.change(amt3,coins3);
*/
	//cin.get(); // pseudo-pause the console
	return 0;
}
