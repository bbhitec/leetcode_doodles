##!/usr/bin/env python
'''
    @author [mst]
    @file   733_flood_fill.py    
    @brief  leetcode problems series
    733. Flood Fill

    An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
    You are also given three integers sr, sc, and color. You should perform a flood fill on the
    image starting from the pixel image[sr][sc].
    To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to
    the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally
    to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
    Return the modified image after performing the flood fill.

    Gains:
    -py matrix operation
    -bfs/dfs recursion methodology

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# Recursive approach: recurse over all valid (adjacent, same color)
# neighbors while coloring the tile if needed
# 
# sub: 92%T 66%T
class Solution:

    # the original color. -1 meaning 'not set'
    orig = -1 

    def floodFill(self, image: [[int]], sr: int, sc: int, color: int) -> [[int]]:

        # basic cases
        if (sr >= len(image)) or (sr < 0): return image
        if (sc >= len(image[0])) or (sc < 0): return image

        # note the color to fill over
        if self.orig == -1:
            self.orig = image[sr][sc]

        # the actual fill        
        if (image[sr][sc] != self.orig) or (image[sr][sc] == color):
            return image     
        else:
            image[sr][sc] = color

        self.floodFill(image, sr, sc + 1, color)
        self.floodFill(image, sr + 1, sc, color)
        self.floodFill(image, sr, sc - 1, color)
        self.floodFill(image, sr - 1, sc, color)
        return image

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
    print ("[mst]")
    
    sol = Solution()

    # image = [[1,1,1],[1,1,0],[1,0,1]]
    image = [[1,1,1,1],[1,1,0,1],[1,1,1,1],[1,1,1,1]]
    print(f"before")
    print_matrix(image)
    sr = 1
    sc = 1
    color = 3
    res = sol.floodFill(image, sr, sc, color)
    print(f"after fill at [{sr},{sc}]")
    print_matrix(res)

    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1
    sc = 1
    color = 2
    res = sol.floodFill(image, sr, sc, color)
    print(f"after fill at [{sr},{sc}]")
    print_matrix(res)



if __name__ == ("__main__"):
    main()
