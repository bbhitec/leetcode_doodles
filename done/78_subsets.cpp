/**
    @author [mst]
    @brief  leetcode series
    78_subsets
    Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    gains:
    -recursion and combi in cpp
    -[next] do the duplicable version

    @version 2024.02
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// list all possible subsets of an array by recursing
// over the set while including\excluding elements as we go
//
//
// 100 53
class Solution {
  vector<vector<int>> res;
  void rec(vector<int> &arr, vector<int> &set, int idx) {
    res.push_back(set);

    for (int i = idx; i < arr.size(); i++) {
      set.push_back(arr[i]);  // include element
      rec(arr, set, i+1);   // expand
      set.pop_back();  // exclude element
    }

  }
public:
  vector<vector<int>> subSets(vector<int> &arr)  {
    res.clear(); // empty set is default

    int idx = 0;
		vector<int> set = {};
    rec (arr, set, idx);
    return res;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> arr = {1,2,2};
    auto res = s.subSets(arr);

    for (vector<int> v : res) {
      cout << "{";
      for (auto &i : v) cout << i << ", ";
      cout << "}" << endl;
    }
    return 0;
}