##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    242_valid_anagram.py
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    gains:
    -python dict (hash map)

    features, changelog:
    -2023.01: -submission

    @version 0.1 2023.01
'''

# build a vocabulary of s and then reduce from t, see if all letters used:
# O(n)
#
# sub: 76%T 65%S
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        voc = {}
        for c in s:
            if c not in voc: voc[c] = 1
            else:
                voc[c] = voc[c] + 1

        for c in t:
            if c not in voc: return False
            else:
                voc[c] = voc[c] - 1
        
        for v in voc:
            if voc[v] != 0: return False

        return True


################## DRIVER
def main():
    
    sol = Solution()

    s = "anagram"
    t = "nagaram"
    print(f"{s=} {t=} res: {sol.isAnagram(s,t)=}")


if __name__ == ("__main__"):
    main()
