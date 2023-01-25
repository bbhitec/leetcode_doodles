'''
 [mst] 51_nqueens.py
 leetcode problems series
    51. N-Queens
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle.
	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
    1 <= n <= 9

    Example 1:
	Input: n = 4
	Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
	Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
	Example 2:
	Input: n = 1
	Output: [["Q"]]

 log
 - 2021.01.22: accepted a backtracking solution. bad time/space
 - initial
 - simple 4x4 case to test if a given spot is safe
 - building a single possible n-queens board as a warm-up
 - find and append all possible solutions, formatted as requested
 - [wip] a smarter diagonals safe check (dales-hills check?)

Created on Jan 11, 2021
@author: mst
'''


class Solution(object):

    QUEEN_SYM = 'Q'
    EMPTY_SYM = '.'

    n = 0
    all_results = []

    def addSolution(self, board):
        # lets return the solution as a string
        strings = []
        for row in board:
            strings.append(''.join(row))
        self.all_results.append(strings)

    # check if the given spot safe for queen placement
    # [wip] test board dimensions before checking
    def isSafe (self, board, row, col):
        if self.QUEEN_SYM in board[row]: # checking rows
            return False
        for rows in board:  # checking columns
            if self.QUEEN_SYM == rows[col]:
                return False

        # checking diagonals
        # [wip] maybe this can be improved
        i = row -1
        j = col -1
        while i>=0 and j>=0:
            if self.QUEEN_SYM == board[i][j]:
                return False
            i = i-1
            j = j-1
        i = row +1
        j = col +1
        while i<self.n and j<self.n:
            if self.QUEEN_SYM == board[i][j]:
                return False
            i = i+1
            j = j+1
        i = row -1
        j = col +1
        while i>=0 and j<self.n:
            if self.QUEEN_SYM == board[i][j]:
                return False
            i = i-1
            j = j+1
        i = row +1
        j = col -1
        while i<self.n and j>=0:
            if self.QUEEN_SYM == board[i][j]:
                return False
            i = i+1
            j = j-1
        return True

    # this recursive method will check and backtrack queen placement per row
    def solveNQueensRowUtil(self,board,row):
        # stopping condition: we went through the board
        if row >= self.n:
            self.addSolution(board) # add this solution
            return True

        for col in range(self.n):
            if self.isSafe(board, row, col):    # find a safe spot
                board[row][col] = self.QUEEN_SYM # put a queen there

                # here we deepen in the recursive call
                self.solveNQueensRowUtil(board,row+1)   # returning true here would yieal only the first solution

                # if we got here, we are backtracking. cleanup and resume
                board[row][col] = self.EMPTY_SYM

        # if we are here, we went through the loop - there's no solution
        return False


    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """

        self.n = n
        self.all_results.clear()

        # using list comprehension to initialize matrix
        board = [ [ self.EMPTY_SYM for i in range(n) ] for j in range(n) ]

        # run the recursive checker
        res = self.solveNQueensRowUtil(board,0)

        return (self.all_results)


# driver
def main():
    print ("[mst] leetcode 51. The n-queens puzzle")

    sol = Solution()

    # case1
    input_n = 8
    res = sol.solveNQueens(input_n)
    print("input: " + str(input_n) + ", result: ")
    print (res)


# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()