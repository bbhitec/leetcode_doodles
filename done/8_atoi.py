##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    8_atoi
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
    The algorithm for myAtoi(string s) is as follows:
    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
    Return the integer as the final result.

    gains:
    -basic math and pyhthon
    -handling a sh!#oad of side cases

    @version 2024.05
'''

# just trim the spaces and walk over the string with an index
#
# sub 74 78
class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if not s:
            return 0

        res = 0
        i = 0
        sign = 1

        MAX_INT = 1<<31

        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1

        while i < len(s):
            if s[i] < '0' or s[i] > '9':
                break
            digit = ord(s[i]) - ord('0')
            res = res*10 + digit
            if res > MAX_INT and sign == -1:
                return -(MAX_INT)
            if res > MAX_INT-1 and sign == 1:
                return (MAX_INT)-1

            i += 1

        return res * sign

################## DRIVER
def main():
    sol = Solution()

    print(sol.myAtoi(s="43"))
    print(sol.myAtoi(s=" "))
    print(sol.myAtoi(s=""))
    print(sol.myAtoi(s="-43"))
    print(sol.myAtoi(s="-+43"))
    print(sol.myAtoi(s="999999999999993"))



if __name__ == ("__main__"):
    main()
