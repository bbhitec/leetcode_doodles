'''
 [mst] <filename>.<extension> title
 description

 log:
 -2021.01: -initial draft
           -another item
 -2020.12: [wip] indicate miscompletion

Created on Jan 11, 2021
@author: mst
'''

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        islands = 'a'
        #islands = chr(ord(islands)+1)
        #print (islands)

        l = len(grid[0])
        for row in range(len(grid)):            
            for col in range(l):
                if (grid[row][col] == '1'):
                    grid[row][col] = islands
                    if (is_island == 0):
                        if(
                        (col<l and (grid[row][col+1] != '1')) and
                        (col>0 and (grid[row][col-1] != '1')) and
                        (col<l and (grid[row+1][col] != '1')) and
                        (col>0 and (grid[row-1][col] != '1'))):
                            num_of_islands += 1 ### [here]
                            is_island = 1
                else:
                    is_island = 0

                print (grid[row][col], end = ' ')
        print (ord(islands)-ord('a'))

        #print (grid)
        


################## DRIVER
def main():
    print ("[mst] leetcode 200. Number of Islands")
    
    sol = Solution()

    grid1 = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]

    grid2 = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]

    sol.numIslands(grid1)

   
if __name__ == ("__main__"):
    main() 
