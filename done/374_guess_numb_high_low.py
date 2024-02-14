##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    374_guess_numb_high_low
    easy
    We are playing the Guess Game. The game is as follows:
    I pick a number from 1 to n. You have to guess which number I picked.

    Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

    You call a pre-defined API int guess(int num), which returns three possible results:

    -1: Your guess is higher than the number I picked (i.e. num > pick).
    1: Your guess is lower than the number I picked (i.e. num < pick).
    0: your guess is equal to the number I picked (i.e. num == pick).
    Return the number that I picked.

    gains:
    -binary search, conditioals


    @version 2024.01
'''

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


# assisting function - use to simulate API
def guess(num: int, guess: int):
    if (guess < num): return 1
    if (guess > num): return -1
    return 0

# use the guess function as a binary search conditional
#
# sub 81 69
class Solution:
    def guessNumber(self, n: int,  k: int) -> int:
        # the boundaries are [1,n]
        l = 1
        r = n

        while l < r:
            mid = (r + l) // 2
            if guess(k,mid) <= 0:
                r = mid
            else:
                l = mid + 1

        return l


################## DRIVER
def main():
    sol = Solution()

    # print (sol.guessNumber(10,9))
    # print (sol.guessNumber(1,1))
    print (sol.guessNumber(2,2))




if __name__ == ("__main__"):
    main()
