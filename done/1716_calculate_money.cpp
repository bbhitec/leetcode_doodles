/**
    @author [mst]
    @brief  leetcode series
    1716_calculate_money
    Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
    He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
    Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

    gains:
    -basic summing
    -math summations: trapezoid sums


    @version 0.1 2023.12
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
using namespace std;


////////////////// DECL_IMPL

// snipped
//
// sub 100, 71
class Solution1 {
public:
  int totalMoney(int n) {
    const int weeks = n / 7;
    const int firstWeek = trapezoid(1, 7);
    const int lastFullWeek = trapezoid(1 + weeks - 1, 7 + weeks - 1);
    const int remainingDays = trapezoid(1 + weeks, n % 7 + weeks);
    return (firstWeek + lastFullWeek) * weeks / 2 + remainingDays;
  }

  int trapezoid(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
  }
};

// naive implementation: run the sum up to n, minding the conditions
//
// sub 100, 35
class Solution {
public:
  int totalMoney(int n) {
    int sum = 0;
    int added = 0;

    for (int i = 0; i < n ; i++) {
      added = (i/7 + 1) + (i%7);  // sum this monday + curr day
      sum += added;
    }

    return sum;
  }
};



////////////////// DRIVER
int main()
{
    Solution s;

    int res = s.totalMoney(20);
    cout << res;


    return 0;
}