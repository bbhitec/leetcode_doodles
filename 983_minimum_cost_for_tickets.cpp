/**
    @author [mst]
    @brief  leetcode series
    983_minimum_cost_for_tickets
    You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
    Train tickets are sold in three different ways:
    a 1-day pass is sold for costs[0] dollars,
    a 7-day pass is sold for costs[1] dollars, and
    a 30-day pass is sold for costs[2] dollars.
    The passes allow that many days of consecutive travel.
    For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
    Return the minimum number of dollars you need to travel every day in the given list of days.

    gains:
    -[wip]


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <queue>
#include <algorithm>        // usage of min
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub 100 81
class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int ans = 0;
        queue<pair<int, int>> last7;
        queue<pair<int, int>> last30;

        for (int day : days) {
            while (!last7.empty() && last7.front().first + 7 <= day)
                last7.pop();
            while (!last30.empty() && last30.front().first + 30 <= day)
                last30.pop();
            last7.emplace(day, ans + costs[1]);
            last30.emplace(day, ans + costs[2]);
            ans = min({ans + costs[0], last7.front().second, last30.front().second});
        }

        return ans;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    int res = s.mincostTickets(days,costs);
    cout << res;


    return 0;
}