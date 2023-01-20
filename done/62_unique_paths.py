##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    62_unique_paths
    There is a robot on an m x n grid. The robot is initially located at the top-left corner
    (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
    The robot can only move either down or right at any point in time.
    Given the two integers m and n, return the number of possible unique paths that the robot
    can take to reach the bottom-right corner.
    The test cases are generated so that the answer will be less than or equal to 2 * 109.

    gains:
    -dfs recursion
    -mathematical combinatorics
    -optimization

    @version 0.1 2023.01
'''

# initial solution:
# use dfs aproach and sum the paths that reached the end
#
# sub: time limit exceeded
class Solution0:
    def uniquePaths(self, m: int, n: int) -> int:

        
        def dfs(self, r: int, c: int)  -> int:
            if r == (m-1) and c == (n-1):
                return 1 # reached the target

            if r == (m-1):
                return 0 + dfs (self, r, c+1)            
            if c == (n-1):
                return 0 + dfs(self, r+1,c)

            return 0 + dfs (self, r, c+1)  + dfs(self, r+1,c)

        paths = dfs(self, 0,0)       
        return paths


# mathematical approach:
# we have to make a total of:
# (no_rows-1) right steps (a decision each row) as well as
# (no_col-1)  left steps (a decision each colunm)
#
# so the number of paths is the amount of combinations to choose a right steps out of overall steps
#
#
# sub: 84%T 98%S
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        import math

        right = m-1
        down = n-1
        all_steps = right + down

        paths = math.factorial(all_steps)//(math.factorial(down) * math.factorial(right))        
        return paths


################## DRIVER
def main():
    sol = Solution()

    # m,n = 3,2
    # print(f"{sol.uniquePaths(m,n)=}")

    # m,n = 3,7
    # print(f"{sol.uniquePaths(m,n)=}")

    # m,n = 2,2
    # print(f"{sol.uniquePaths(m,n)=}")

    m,n = 23,12
    print(f"{sol.uniquePaths(m,n)=}")


if __name__ == ("__main__"):
    main()
