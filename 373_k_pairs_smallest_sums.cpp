/**
    @author [mst]
    @brief  leetcode series
    373_k_pairs_smallest_sums

    You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
    Define a pair (u, v) which consists of one element from the first array and one element from the second array.
    Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


    gains:
    -[wip] rd solutions
    -[wip] refresh on emplace
    -[wip] redocument lambdas

    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <queue>        // use of priority_queue
using namespace std;


////////////////// DECL_IMPL

// struct T {
//   int i;
//   int j;
//   int sum; // nums1[i] + nums2[j]
//   T(int i, int j, int sum) : i(i), j(j), sum(sum) {}
// };

// snipped
// recursive dp solution:
// memoizing possible finishes for current location given an amount of fuel
//
// sub 77 90
class Solution {
public:
  struct T {
    int i;
    int j;
    int sum; // nums1[i] + nums2[j]
    T(int i, int j, int sum) : i(i), j(j), sum(sum) {}
  };

  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<vector<int>> ans;
    auto compare = [&](const T &a, const T &b)
    { return a.sum > b.sum; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

    for (int i = 0; i < k && i < nums1.size(); ++i)
      minHeap.emplace(i, 0, nums1[i] + nums2[0]);

    while (!minHeap.empty() && ans.size() < k)
    {
      const auto [i, j, _] = minHeap.top();
      minHeap.pop();
      ans.push_back({nums1[i], nums2[j]});
      if (j + 1 < nums2.size())
        minHeap.emplace(i, j + 1, nums1[i] + nums2[j + 1]);
    }
    return ans;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
    int k = 3;
    vector<vector<int>> res = s.kSmallestPairs(nums1,nums2,k);
    for (vector<int> &v : res) {
      cout << "[";
      for (auto &m : v) {
        cout << m << ", ";
      }
      cout << "]";
    }

    return 0;
}