/**
    @author [mst]
    @brief  leetcode series
    78_subsets
    Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

    gains:
    -recursion and combi in cpp
    -using cpp move when passing rvalue
    -[next] do the duplicable version

    @version 2024.02
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// refresher 2024.05
// used the move() xvalue changer
//
// sub 100 94
class Solution {
private:
    void dfs(vector<vector<int>>& res,vector<int>& nums, vector<int>&& set, int idx){
      res.push_back(set); // save this set

      for (int i = idx; i < nums.size(); i++) { // for each next member...
        set.push_back(nums[i]); // include it in next sets...
        dfs(res, nums, move(set), i+1); // recurse...
        set.pop_back(); // and remove it from next sets
      }

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, {}, 0);

        return res;
    }
};

// list all possible subsets of an array by recursing
// over the set while including\excluding elements as we go
// time O(2^n)
// space O(n*2^n)
//
// 100 53
class Solution1 {
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
  vector<vector<int>> subsets(vector<int> &arr)  {
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
    auto res = s.subsets(arr);

    for (vector<int> v : res) {
      cout << "{";
      for (auto &i : v) cout << i << ", ";
      cout << "}" << endl;
    }
    return 0;
}