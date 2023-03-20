/**
    @author [mst]
    @brief  leetcode series
    605_can_place_flowers
    You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
    Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

    gains:
    -simple cpp conditionals


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 100, 34
class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (n == 0)
            return true;

        for (int i = 0; i < flowerbed.size(); ++i)
            // check if adjacent slots are free (or are the limits)
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                if (--n == 0)
                    return true;
            }

        return false;
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    cout << s.canPlaceFlowers(flowerbed, n);

    return 0;
}