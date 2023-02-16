/**
    @author [mst]
    @brief  leetcode problems series
    1232_check_straight_line
    You are given an array coordinates, coordinates[i] = [x, y],
	where [x, y] represents the coordinate of a point.
	Check if these points make a straight line in the XY plane.

    gains:
	-algorithmic math concepts

    @version 0.1 2023.02
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// calculate the slpe and check its consistency for all given coordinate points
//
// sub: 91T 93S
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int c = coordinates.size();

        // if only two points, they make a line
        if (c <= 2) return true;

        // calculate initial slope to be maintained by all points
        int dx = coordinates[0][0] - coordinates[1][0];
        int dy = coordinates[0][1] - coordinates[1][1];

        // check that the rest of the points have the same point
        // note that point coordinates[0] will be common to all points
        for (int i = 2; i < c; ++ i) {
            int dx1 = coordinates[0][0] - coordinates[i][0];
            int dy1 = coordinates[0][1] - coordinates[i][1];
            if (dx1 * dy != dy1 * dx) return false;
        }
        return true;
    }
};



////////////////// DRIVER
int main()
{
	Solution sol;

	vector<vector<int>> coordinates = {
		{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}
	};

	cout << sol.checkStraightLine(coordinates) << endl;

	return 0;
}
