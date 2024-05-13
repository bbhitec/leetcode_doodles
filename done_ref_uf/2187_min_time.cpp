/**
    @author [mst]
    @brief  leetcode series
    2187_min_time
	You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
    Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
    You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

    gains:
    -[wip] rd the solution


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <algorithm>        // min_element
#include <numeric>          // accumulate
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 100t 73s
class Solution {
public:
    long long minimumTime(vector<int> &time, int totalTrips) {
        long long l = 1;
        long long r = *min_element(begin(time), end(time)) * static_cast<long>(totalTrips);

        while (l < r) {
            const long long m = (l + r) / 2;
            if (numTrips(time, m) >= totalTrips)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    long numTrips(const vector<int> &times, long m) {
        return accumulate(begin(times), end(times), 0L,
                          [&](long subtotal, int t)
                          { return subtotal + m / t; });
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    // vector<int> time = {1,2,3};
    // int totalTrips = 5;
    // int res = s.minimumTime(time,totalTrips);
    // cout << res;

    int kMod = 1'000'000'007;
    cout << kMod;


    return 0;
}