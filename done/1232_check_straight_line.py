##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    1232_check_straight_line
    You are given an array coordinates, coordinates[i] = [x, y],
	where [x, y] represents the coordinate of a point.
	Check if these points make a straight line in the XY plane.

    gains:
	-basic linear math
    -basic array orientation


    @version 0.1 2023.06
'''

# keep the slope on each point relating the first, make sure keep differential
#
# sub 33 26
class Solution:
    def checkStraightLine(self, coordinates: [[int]]) -> bool:
        # check if more than one point
        sz = len(coordinates)
        if (sz < 2):
            return True

        dx = coordinates[0][0] - coordinates[1][0]
        dy = coordinates[0][1] - coordinates[1][1]

        for i in range(2,sz):
            # current slope
            dxi = coordinates[0][0] - coordinates[i][0]
            dyi = coordinates[0][1] - coordinates[i][1]
            # check differential: dy/dyi == dx/dxi
            if (dy * dxi) != (dx * dyi):
                return False

        return True


################## DRIVER
def main():

    sol = Solution()
    coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    print(f"{coordinates=}")
    print(f"{sol.checkStraightLine(coordinates)=}")

    print("")

    coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    print(f"{coordinates=}")
    print(f"{sol.checkStraightLine(coordinates)=}")


if __name__ == ("__main__"):
    main()
