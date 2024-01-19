/**
    @author [mst]
    @brief  leetcode series
    1207_unique_number_occurrences
    Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

    gains:
    -wip


    @version 0.1 2024.01
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


////////////////// DECL_IMPL

// [bp] improve upon previous solution by using better structures and methods:
// -unordered map and set
// -checking set uniqueness with insert rather than count
//
// sub 100 40
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // counter for each number encountered
        unordered_map<int, int> histogram;
        for (auto &&num : arr) histogram[num]++;

        // add to set checking uniqueness of the appearance counts
        unordered_set<int> uniques;
        for (const auto& [_, value] : histogram)
            if (!uniques.insert(value).second)
                return false;
        return true;
    }
};

// build an appearances histogram then check if any count/value appears more than once
//
// sub 65 20
class Solution0 {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // counter for each number encountered
        map<int, int> histogram;
        for (auto &&num : arr) histogram[num]++;

        // add to set checking uniqueness of the appearance counts
        set<int> unique;
        for (auto &&p : histogram) {
            if (unique.count(p.second)) return false;
            unique.insert(p.second);
        }
        return true;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> arr = {1,2,2,1,1,3,};
    cout << s.uniqueOccurrences(arr) << endl;
    arr = {1,2};
    cout << s.uniqueOccurrences(arr) << endl;
    arr = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << s.uniqueOccurrences(arr) << endl;

    return 0;
}