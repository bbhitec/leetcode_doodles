/**
    @author [mst]
    @brief  leetcode series
    2305_fair_distribution_cookies
    You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
    The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
    Return the minimum unfairness of all distributions.

    gains:
    -[wip] rd solutions


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


////////////////// DECL_IMPL



// snipped
//
// sub 26 62
class Solution {
public:
  int distributeCookies(vector<int> &cookies, int k) {
    int ans = INT_MAX;
    dfs(cookies, 0, k, vector<int>(k), ans);
    return ans;
  }

private:
  void dfs(const vector<int> &cookies, int bag, int k, vector<int> &&children, int &ans) {

    // went through all the cookie bags
    if (bag == cookies.size()) {
      ans = min(ans, *max_element(children.begin(), children.end()));
      return;
    }

    // put the current bag to each child
    for (int i = 0; i < k; ++i) {
      children[i] += cookies[bag];
      dfs(cookies, bag + 1, k, move(children), ans);
      children[i] -= cookies[bag];
    }
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> cookies = {8,15,10,20,8};
    int k = 2;
    int res = s.distributeCookies(cookies,k);
    cout << res;


    return 0;
}