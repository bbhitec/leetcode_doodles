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
    -2023.01.25 -optimized: don't pass the image in the dfs
    -2023.01: -submission
'''

# one land is spotted, flood fill given island with null value while adding to a counter
#
# sub: 73%T 65%S
class Solution0:
    def numIslands(self, grid: [[str]]) -> int:
        num = 0

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == "1":
                    self.consumeIsland(grid, row,col)
                    num = num + 1

        # print("after:")
        # print_matrix(grid)
        return num

    def consumeIsland(self, image: [[int]], sr: int, sc: int):
        # basic cases
        if (sr >= len(image)) or (sr < 0): return
        if (sc >= len(image[0])) or (sc < 0): return

        if image[sr][sc] != "1": return
        else:
            image[sr][sc] = "0"

        self.consumeIsland(image, sr, sc + 1)
        self.consumeIsland(image, sr + 1, sc)
        self.consumeIsland(image, sr, sc - 1)
        self.consumeIsland(image, sr - 1, sc)
        return

# optimized: don't pass the image in the dfs
#
# sub: 98T 64S
class Solution:
    def numIslands(self, grid: [[str]]) -> int:

        def consumeIsland(sr: int, sc: int):
            # basic cases
            if (sr >= rows) or (sr < 0): return
            if (sc >= cols) or (sc < 0): return

            if grid[sr][sc] != "1": return
            else:
                grid[sr][sc] = "0"

            consumeIsland(sr, sc + 1)
            consumeIsland(sr + 1, sc)
            consumeIsland(sr, sc - 1)
            consumeIsland(sr - 1, sc)
            return

        rows = len(grid)
        cols = len(grid[0])
        num = 0

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1":
                    consumeIsland(row,col)
                    num = num + 1

        # print("after:")
        # print_matrix(grid)
        return num

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

    grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","1"],
    ["0","0","0","1","0"]
    ]

    print(f"before:")
    print_matrix(grid)
    print(f"{sol.numIslands(grid)=}")


if __name__ == ("__main__"):
    main()
