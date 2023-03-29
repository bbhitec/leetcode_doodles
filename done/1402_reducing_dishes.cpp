/**
    @author [mst]
    @brief  leetcode series
    1402_reducing_dishes
	A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
	Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
	Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
	Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

    gains:
	-cpp basic sort
	-algo thinking
	-prefix sum

    @version 0.1 2023.03
*/


////////////////// LIBS
#include <iostream>				// usage of console prints
#include <vector>
#include <algorithm>			// sorting

using namespace std;


////////////////// DECL_IMPL

// We sort the dishes by score (best to worst) and accumulate positive prefix sums.
// Once the prefix sum is negative, it will not raise the overall score.
// Hence, we forfeit the rest of the dishes (since they can only give
// worse score as they are sorted)
//
//
// sub: 85 89 (while loop)
//      94 77 (for loop)
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

		// sort the dishes scores, best first
		sort(satisfaction.begin(),satisfaction.end(),greater());

		int total = 0;	// best score reached
		int prefix = 0;	// prefix sum of added dish
		int size = satisfaction.size();

		for (int i = 0; i < size; i++) {
			prefix += satisfaction[i];

			// if the prefix sum is positive, this dish
			// will contribute to the overall score
			if (prefix >= 0) total += prefix;
			else break;
		}
		return total;
    }
};

////////////////// DRIVER
int main()
{
	Solution s;
	// vector<int> satisfaction = {-1,-8,0,5,-9};
	vector<int> satisfaction = {4,3,2};
	// vector<int> satisfaction = {-1,-4,-5};

	cout << s.maxSatisfaction(satisfaction);
	return 0;
}
