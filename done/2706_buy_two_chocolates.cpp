/**
    @author [mst]
    @brief  leetcode series
    2706_buy_two_chocolates
    You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.
    You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.
    Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative.

    gains:
    -basic sorting
    -maintaining two minimal values


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>
using namespace std;


////////////////// DECL_IMPL

// sort and check firts two members
//
// sub 100 58
class Solution1 {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int res = money - prices[0] - prices[1];
        return (res >= 0)? res: money;
    }
};

// dont sort, seek the two minimal values
//
// sub 25 29
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 100;
        int min2 = 100;

        for (auto &p : prices) {
          if (p < min1) {
            min2 = min1;
            min1 = p;
            continue;
          }
          if (p < min2) min2 = p;
        }

        int res = money - min1 - min2;
        return (res >= 0)? res: money;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> prices = {1,2,2}; int money = 3;
    // vector<int> prices = {3,2,3}; int money = 3;
    vector<int> prices = {69,91,78,19,40,13}; int money = 94;
    int res = s.buyChoco(prices, money);
    cout << res;


    return 0;
}