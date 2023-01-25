/**
    @author [mst]
    @file   twosum.cpp
    @brief  leetcode problems series

    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
	You may assume that each input would have exactly one solution, and you may not use the same element twice.
	Example:
	Given nums = [2, 7, 11, 15], target = 9,
	Because nums[0] + nums[1] = 2 + 7 = 9,
	return[0, 1].


    Gains:
    -Has map usage and indexing


    features, changelog:
	-2022.11 a solution using the unordered map
    -2021: -initial draft: naive iteratve solution, O(n^2) time

    @version 0.1 2021
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <unordered_map>
using namespace std;

////////////////// DECL_IMPL

class Solution {
public:
	// naive solution, nested loop with two indices to spot a matching pair
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		using std::vector;	// [demo] we can improve readability by importing std selectively
		vector<int> result;
		for (vector<int>::iterator id1 = nums.begin(); id1 != nums.end(); ++id1) {
			for (vector<int>::iterator id2 = nums.begin(); id2 != nums.end(); ++id2) {
				if ((id1 != id2) && ((*id1 + *id2) == target)) {
					result.push_back(std::distance(nums.begin(), id1));
					result.push_back(std::distance(nums.begin(), id2));
					return result;
				}
			}
		}
		return result;	// will return empty vector if no pair is found
	}
};

class SolutionHash {
public:
	// using the STL unordered map T: 64.2% S: 44.68%
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		using std::unordered_map; // [demo] we can improve readability by importing std selectively
		using std::vector;
		vector<int> result;
		unordered_map<int, int> diffs_umap;
		unordered_map<int, int>::iterator itr2;
		int diff = 0;

		for (vector<int>::iterator itr1 = nums.begin(); itr1 != nums.end(); ++itr1) {
			diff = target - *itr1;
			itr2 = diffs_umap.find(*itr1);
			if (itr2 != diffs_umap.end()) {
				// found a match
				result.push_back(itr2->second);
				result.push_back(std::distance(nums.begin(), itr1)); // current index
				return result;
			}
			else {
				diffs_umap[diff] = std::distance(nums.begin(), itr1);
			}

		}
		return result;
	}
};


////////////////// DRIVER
int main()
{
	cout << "[mst] leetcode 1. two sum problem" << endl << endl;

	// test case1
	int test_target	= 9;
	vector<int> arr_vec = {7, 1, 3, 31, 11, 2, 15};

	Solution solution;
	vector<int> result = solution.twoSum(arr_vec, test_target);
	cout << "solution1: " << endl << endl;
	for (const auto& member : result) {		// [demo] using 'auto' for type inference and a more generic approach
		std::cout << member << ", ";
	}

	SolutionHash sol_hash;
	vector<int> result2 = sol_hash.twoSum(arr_vec, test_target);
	cout << "\nsolution1hash: " << endl << endl;
	for (const auto& member : result2) {		// [demo] using 'auto' for type inference and a more generic approach
		std::cout << member << ", ";
	}


	return 0;
}
