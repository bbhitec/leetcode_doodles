/**
    @author [mst]
    @brief  leetcode series
    881_boats_to_save_people
    You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
    Return the minimum number of boats to carry every given person.

    gains:
    -[wip]


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 90 59
class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(begin(people), end(people));

        int boats = 0;
        // boat carries at most two people
        // each iteration will 'fill' one boat
        for (int i = 0, j = people.size() - 1; i <= j; ++boats) {
            int remain = limit - people[j--];   // put a heavy person
            if (people[i] <= remain)    // put a light person
                ++i;
        }

        return boats;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    vector<int> people = {3,2,2,1};
    int limit = 3;
    int res = s.numRescueBoats(people,limit);
    cout << res;


    return 0;
}