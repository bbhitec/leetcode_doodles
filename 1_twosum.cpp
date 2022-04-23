//
// [mst] twosum1.cpp
// leetcode problems series
//
//		1. Two Sum
//		Given an array of integers, return indices of the two numbers such that they add up to a specific target.		
//		You may assume that each input would have exactly one solution, and you may not use the same element twice.		
//		Example:
//		Given nums = [2, 7, 11, 15], target = 9,		
//		Because nums[0] + nums[1] = 2 + 7 = 9,
//		return[0, 1].
//
//
// features, changelog:
// - [wip] initial
// - [wip] use hashtab
// - [wip] use references and functions
//
//

////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;

////////////////// DECL_IMPL

class Solution {

public:

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
		return result;
	}
};


////////////////// DRIVER
int main()
{
	cout << "[mst] leetcode 1. two sum problem" << endl << endl;

	// [demo] array declaration and initialization
	const int length = 3;	// the size is const
	int stack_array[length] = { 0, 32, 54 };		// this will cteate an (static)  array on the stack for the current scope (no delete needed)
	int* array = new int[length];					// this will create an (dynamic) array on the heap. we have to delete it when done
	std::copy(/*input start*/ array, /*input end*/ array + length, /*result address*/ &stack_array[0]);


	delete[] array;

	// test case1 : [2, 7, 11, 15], sum 9
	int test_arr1[] = {11, 7, 2, 15};
	int test_target		= 9;

	vector<int> arr_vec;
	for (int i = 0; i < 4; i++) {
		arr_vec.push_back(test_arr1[i]);
	}

	Solution solution;
	vector<int> result = solution.twoSum(arr_vec, test_target);
	cout << "solution1: " << endl << endl;

	for (const auto& member : result) {		// [demo] using 'auto' for type inference and a more generic approach
		std::cout << member << ", ";
	}

	// [wip] time this against a hash solution ...

	// system("pause");    // [mst][demo] this is not portable!!
	cin.get(); // pseudo-pause the console
	return 0;
}
