##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    566_reshape_matrix
    In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
    You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
    The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
    If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
    
    Gains:
    -python basic matrix operation

    features, changelog:
    -initial

    @version 0.1 2023.01
'''


# if the dimensions are legal, built a line from all elements
# then cascade in a desired dimensions
#
# sub: 80%T 34%S
class Solution:
    def matrixReshape(self, mat: [[int]], r: int, c: int) -> [[int]]:
        size_mat = len(mat) * len(mat[0])
        if size_mat != (r*c): return mat

        res = []
        linear = []

        for row, row_val in enumerate(mat):
            for col, col_val in enumerate(mat[row]):
                #print(f"{mat[row][col]} ", end='')
                linear.append(mat[row][col])
            #print("")

        for i in range(r):
            line = []
            for j in range(c):
                if linear: line.append(linear.pop(0))
            res.append(line)       
        
        return res


################## DRIVER
def main():
    
    sol = Solution()
    mat = [[1,2],[3,4]]
    r = 2
    c = 4

    res = sol.matrixReshape(mat,r,c)
    print(f"testing {mat=} {r=} {c=} res: {res=}")

    

if __name__ == ("__main__"):
    main()
