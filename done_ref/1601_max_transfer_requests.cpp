/**
    @author [mst]
    @brief  leetcode series
    1601_max_transfer_requests
    We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.
    You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building fromi to building toi.
    All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.
    Return the maximum number of achievable requests.

    gains:
    -[wip] rd solutions
    -[wip] function directive - to document
    -[wip] all_of directive - to document


    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <functional>   // use of function
using namespace std;


////////////////// DECL_IMPL



// snipped - walkcc reference
//
// sub
class Solution {
private:
  int ans;
  void dfs (int i, int processedReqs, vector<vector<int>> &requests, vector<int> &degree) {
      if (i == requests.size()) {
        for (int d : degree) if (d!=0) return;
          // spotted a settling case, note for max
          ans = max(ans, processedReqs);
        return;
      }

      // ignore request
      dfs(i + 1, processedReqs, requests, degree);

      // consider request
      degree[requests[i][0]]--;
      degree[requests[i][1]]++;
      dfs(i + 1, processedReqs + 1, requests, degree);
      degree[requests[i][1]]--;
      degree[requests[i][0]]++;
    };

public:
  int maximumRequests(int n, vector<vector<int>> &requests) {
    ans = 0;
    vector<int> degree(n);
    dfs(0, 0, requests, degree);
    return ans;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    int n = 5;
    vector<vector<int>> requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};

    int res = s.maximumRequests(n, requests);
    cout << res;


    return 0;
}