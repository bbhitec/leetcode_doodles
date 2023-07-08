/**
    @author [mst]
    @brief  leetcode series
    2551_marbles_in_bags
    You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
    Divide the marbles into the k bags according to the following rules:
    -No bag is empty.
    -If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
    -If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
    The score after distributing the marbles is the sum of the costs of all the k bags.
    Return the difference between the maximum and minimum scores among marble distributions.

    gains:
    -[wip] rd solution

    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>
using namespace std;


////////////////// DECL_IMPL

// snipped - walkcc reference
// To distribute marbles into k bags, there will be k - 1 cuts. If there's a
// cut after weights[i], then weights[i] and weights[i + 1] will be added to
// the cost. Also, no matter how we cut, weights[0] and weights[n - 1] will
// be counted. So, the goal is to find the max/min k - 1 weights[i] +
//
// sub 49 80
class Solution {
public:
  long long putMarbles(vector<int> &weights, int k)
  {
    vector<int> sums; // weights[i] + weights[i + 1]
    long long min = 0;
    long long max = 0;
    int sz = weights.size();

    for (int i = 0; i + 1 < sz; ++i) {
      sums.push_back(weights[i] + weights[i + 1]);
    }

    // sort sums array to look for minimal sum from the left and max from right
    sort(sums.begin(), sums.end());
    for (int i = 0; i < k - 1; ++i) {
      min += sums[i];
      max += sums[sums.size() - 1 - i];
    }

    return max - min;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> weights = {1,3,5,1};
    int k = 2;

    int res = s.putMarbles(weights,k);
    cout << res;

    return 0;
}