##!/usr/bin/env python
'''
    @author [mst]
    @file   .py    
    @brief  leetcode problems series
    1790. Check if One String Swap Can Make Strings Equal
    
    You are given two strings s1 and s2 of equal length.
    A string swap is an operation where you choose two indices
    in a string (not necessarily different) and swap the characters at these indices.

    Return true if it is possible to make both strings equal by
    performing at most one string swap on exactly one of the strings.
    Otherwise, return false.

    gains:
    -conditionals

    features, changelog:
    -2022.11: -submission

    @version 0.1 2022.11
'''

# traverse both strings looking for a mismatch. once it is me, note it and look for a comtatible swap
# 1 <= s1.length, s2.length <= 100
# s1.length == s2.length
# s1 and s2 consist of only lowercase English letters.
#
# sub: 86%T 21%S
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True

        mapping = []
        swapped = 0

        # if we see more than two mismatches
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if swapped == 1: return False
                if len(mapping) == 0: mapping.append([s1[i],s2[i]])
                else:
                    if (mapping[0][0] != s2[i]) or (mapping[0][1] != s1[i]): return False
                    else: swapped = 1

        if swapped == 0: return False

        return True




################## DRIVER
def main():
    sol = Solution()

    # testing
    s1 = "bank"
    s2 = "kanb"
    print(sol.areAlmostEqual(s1,s2))

    s1 = "aa"
    s2 = "ac"
    print(sol.areAlmostEqual(s1,s2))
    

if __name__ == ("__main__"):
    main()
