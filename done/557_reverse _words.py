##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    557. Reverse Words in a String III
    Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    gains:
    -python string manipulation
    -string to list and back

    features, changelog:
    -2023.01: -submission

    @version 0.1 2023.01
'''

# quick little list comprehension to a list
# sub: 33%T 43%S
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join([word[::-1] for word in s.split()])



################## DRIVER
def main():
    
    sol = Solution()

    s = "Let's take LeetCode contest"
    print(sol.reverseWords(s))


if __name__ == ("__main__"):
    main()
