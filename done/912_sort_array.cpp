/**
    @author [mst]
    @brief  leetcode series
    912_sort_array
	full/optional description: this is a placeholder
    template for new files creation
	Given an array of integers nums, sort the array in ascending order and return it.
	You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

    gains:
    -smerge sorting algorithm in cpp


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// merge sort approach:
// partially snipped
//
// sub: 28s 29t
class Solution {
private:
	void mergeSort(vector<int> &A, int l, int r) {
		if (l >= r)
			return;

		const int m = (l + r) / 2;
		mergeSort(A, l, m);
		mergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}

	void merge(vector<int> &A, int l, int m, int r) {
		vector<int> sorted(r - l + 1);
		int k = 0;	   
		int i = l;	   
		int j = m + 1; 

		while (i <= m && j <= r)
			if (A[i] < A[j])
				sorted[k++] = A[i++];
			else
				sorted[k++] = A[j++];

		// handle leftovers
		while (i <= m) sorted[k++] = A[i++];
		while (j <= r) sorted[k++] = A[j++];

		copy(begin(sorted), end(sorted), begin(A) + l);
	}
public:
	vector<int> sortArray(vector<int> &nums) {
		mergeSort(nums, 0, nums.size() - 1);
		return nums;
	}


};

////////////////// DRIVER
int main()
{
	Solution s;
	vector<int> nums = {5,2,3,1};

	for (const auto& n : nums) cout << n << ", ";
	cout << endl;
	vector<int> res = s.sortArray(nums);
	for (const auto& n : res) cout << n << ", ";
	cout << endl;
	return 0;
}
