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

# [here] calculating size as-we-go
class Solution:
    def maxAreaOfIsland(self, grid: [[int]]) -> int:
        def consumeIsland(image: [[int]], sr: int, sc: int, size: int) -> int:
        # basic cases
            if (sr >= len(image)) or (sr < 0): return 0
            if (sc >= len(image[0])) or (sc < 0): return 0

            if image[sr][sc] != 1: return 0
            else:
                image[sr][sc] = 0
                size = size + 1

            r = consumeIsland(image, sr, sc + 1, size)
            d = consumeIsland(image, sr + 1, sc, size)
            l = consumeIsland(image, sr, sc - 1, size)
            u = consumeIsland(image, sr - 1, sc, size)

            return size+ r + d + l + u


        size = 0
        max_size = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    size = consumeIsland(grid, row, col, 0)
                    print (size)
                    if size > max_size: max_size = size

        print("after")
        print_matrix(grid)

        # sizes = [0 for n in range(color)]
        # for row in grid:
        #     for col in row:
        #         if col != 0: sizes[col] = sizes[col] +1

        # print(f"{sizes=}")
        return 1#max(sizes)

# first, paint individual islands with distinct colors (use fill algoritm)
# then build an occurance historgram and derive the maximal value
#
# sub: 93%T 58%S
class Solution0:
    def maxAreaOfIsland(self, grid: [[int]]) -> int:
        def consumeIsland(image: [[int]], sr: int, sc: int, color):
        # basic cases
            if (sr >= len(image)) or (sr < 0): return
            if (sc >= len(image[0])) or (sc < 0): return


            if image[sr][sc] != 1: return
            else:
                image[sr][sc] = color
                #return

            consumeIsland(image, sr, sc + 1, color)
            consumeIsland(image, sr + 1, sc, color)
            consumeIsland(image, sr, sc - 1, color)
            consumeIsland(image, sr - 1, sc, color)


        color = 2
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == 1:
                    consumeIsland(grid, row, col, color)
                    color = color + 1

        # print("after")
        # print_matrix(grid)

        sizes = [0 for n in range(color)]
        for row in grid:
            for col in row:
                if col != 0: sizes[col] = sizes[col] +1

        # print(f"{sizes=}")
        return max(sizes)




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
