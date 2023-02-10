##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    344_reverse_string
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.

    gains:
    -python loop boundaries
    -mirror-traversal



    features, changelog:
    -2023.01: -submission

    @version 0.1 2023.01
'''

# simple mirror-traverse swap
# sub: 26%T 41%S
class Solution:
    def reverseString(self, s: [str]) -> None:
        size = len(s)
        rang = size//2

        for i in range(rang):
            tmp = s[i]
            s[i] = s[size-i-1]
            s[size-i-1] = tmp

        print(s)



################## DRIVER
def main():

    sol = Solution()

    s = ["h","e","l","l","o","o"]
    sol.reverseString(s)


if __name__ == ("__main__"):
    main()
