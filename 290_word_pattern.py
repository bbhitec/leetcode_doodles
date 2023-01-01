##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    290_word_pattern
    Given a pattern and a string s, find if s follows the same pattern.
    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

    Constraints:
    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lowercase English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.

    
    Gains:

    features, changelog:
    -initial

    @version 0.1 2023.01
'''


#
#
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        
        # pattern contains only lower-case English letters!
        letters = []
        corresponding = []
        hash_matches = {}
        reverse = {}
        
        for i in range(len(pattern)):
            hash_matches[c] = #[here]

        return False


################## DRIVER
def main():
    
    sol = Solution()

    pattern = "abba"
    s = "dog cat cat dog"
    res = sol.wordPattern(pattern, s)
    print(f"testing {pattern=} string {s=}: {res}")

    



if __name__ == ("__main__"):
    main()
