/**
    @author [mst]
    @brief  leetcode series
    1575_count_possible_routes
    You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.
    At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.
    Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
    Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 109 + 7.

    gains:
    -[wip] rd solutions
    -[wip] rd walkccc solution


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
using namespace std;


////////////////// DECL_IMPL


// snipped
// recursive dp solution:
// memoizing possible finishes for current location given an amount of fuel
//
// sub
class Solution {
private:
  static constexpr int kMod = 1'000'000'007;
  int dp[105][205] = {0};
  int fin;
  vector<int> loc;

  int recur(int idx, int fuel)   {
    int ans = 0;
    if (idx == fin) ans++;

    // infer memo
    if (dp[idx][fuel] != -1) return dp[idx][fuel];

    for (int i = 0; i < loc.size(); i++) {
      if (i != idx && abs(loc[i] - loc[idx]) <= fuel) {
        ans += recur(i, fuel - abs(loc[i] - loc[idx]));
        ans %= kMod;
      }
    }
    return dp[idx][fuel] = ans;
  }

public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        fin = finish;
        loc = locations;
        memset(dp, -1, sizeof(dp));
        return recur(start, fuel);
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> locations = {2,3,6,8,4};
    int start = 1, finish = 3, fuel = 5;
    int res = s.countRoutes(locations,start,finish,fuel);
    cout << res;


    return 0;
}