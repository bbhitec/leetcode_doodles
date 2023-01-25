##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    200_num_of_islands
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    Gains:
    -python list of lists (matrix) operation,
    -bfs/dfs matrix traversal

    features, changelog:
    -2023.01: -submission
'''

# one land is spotted, flood fill given island with null value while adding to a counter
#
# sub: 29%T 65%S
class Solution:
    def maxAreaOfIsland(self, grid: [[int]]) -> int:
        sizes = []

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    size_i = self.consumeIsland(grid, row,col)
                    sizes.append(size_i) [here]

        print(f"{sizes=}")
        # print_matrix(grid)
        return max(sizes)

    def consumeIsland(self, image: [[int]], sr: int, sc: int):
        # basic cases
        if (sr >= len(image)) or (sr < 0): return 0
        if (sc >= len(image[0])) or (sc < 0): return 0

        size = 0

        if image[sr][sc] != 1: return 0
        else:
            image[sr][sc] = 0
            size = size + 1
            return size

        size = size + self.consumeIsland(image, sr, sc + 1)
        size = size + self.consumeIsland(image, sr + 1, sc)
        size = size + self.consumeIsland(image, sr, sc - 1)
        size = size + self.consumeIsland(image, sr - 1, sc)
        return size


# helper method: print as table
def print_matrix(image):
    if image is None:
        return

    for row in image:
        for col in row:
            print(f"{col} ", end='')
        print("")


################## DRIVER
def main():

    sol = Solution()

    grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]

    print(f"before:")
    print_matrix(grid)
    print(f"{sol.maxAreaOfIsland(grid)=}")


if __name__ == ("__main__"):
    main()
