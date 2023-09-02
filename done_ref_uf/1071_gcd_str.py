##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    2366_min_replacements_to_sort
    For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
    Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

    gains:
    -[wip] rd the snipped solution


    @version 0.1 2023.08.31
'''

# snipped walkccc
#
# sub 43 74
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def mod(s1: str, s2: str) -> str:
            while s1.startswith(s2):
                s1 = s1[len(s2):]
            return s1

        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)
        if not str1.startswith(str2):
            return ''
        if not str2:
            return str1
        return self.gcdOfStrings(str2, mod(str1, str2))

################## DRIVER
def main():
    sol = Solution()

    str1 = "ababab"
    str2 = "ab"

    res = sol.gcdOfStrings(str1, str2)
    print (res)



if __name__ == ("__main__"):
    main()
