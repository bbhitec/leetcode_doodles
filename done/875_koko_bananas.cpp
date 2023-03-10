/**
    @author [mst]
    @brief  leetcode series
    875_koko_bananas
	Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
	Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
	Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
	Return the minimum integer k such that she can eat all the bananas within h hours.

    gains:
	-binary search orientation and algorithmic thinking


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <algorithm>	// usage of max and max element
using namespace std;


////////////////// DECL_IMPL

// approach: perform a binary search over the possible k values {1..max(piles)}
// snipped some optimizations
//
// sub: 95t 45s
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
		int sz = piles.size();
		int l = 1;
		int r = *max_element(begin(piles), end(piles));
		int res = INT_MAX;

		// if number of piles equals the hours, we have to eat at maximal rate
		if (h == sz) return r;

		while (l<r) {
			int k = (r+l)/2;
			if (hoursToEat(piles, k) <= h) {
				r = k;
			} else {
				l = k+1;
			}
		}

		return l;
    }

	// check the number of hours it takes to eat the piles for the rate of k
	int hoursToEat (vector<int>& piles, int k) {
		int hours = 0;
		for (auto &&i : piles) {
			hours += (i + k - 1) / k;	// [demo] ceil division (might overflow)
		}
		return hours;
	}
};

////////////////// DRIVER
int main()
{
	Solution s;

	vector<int> piles = {3,6,7,11}; int h = 8;
	// vector<int> piles = {30,11,23,4,20}; int h = 5;
	// vector<int> piles = {30,11,23,4,20}; int h = 6;

	cout << s.minEatingSpeed(piles, h);
	return 0;
}
