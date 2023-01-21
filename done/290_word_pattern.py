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


# keep a vocabulary of pattern matches and a reverse order
# make sure it is consistent throughout the pattern
#
# sub: 41%T 12%S
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        patt_lenght = len(pattern)
        if len(words) != patt_lenght: return False

        voc = {}
        reverse = {}
        for i in range(patt_lenght):
            ch = pattern[i]
            word = words[i]
            if (ch not in voc):
                # make sure the backward relation is unique
                if word in reverse: return False
                voc[ch] = word
                reverse[word] = ch
            else:
                if voc[ch] != word: return False
                if reverse[word] != ch: return False

        return True


################## DRIVER
def main():    
    sol = Solution()

    pattern, s = "abba", "dog cat cat dog"
    res = sol.wordPattern(pattern, s)
    print(f"testing {pattern=} string {s=}: {res}")
    pattern, s = "abba", "dog cat cat fish"
    res = sol.wordPattern(pattern, s)
    print(f"testing {pattern=} string {s=}: {res}")
    pattern, s = "aaaa", "dog cat cat dog"
    res = sol.wordPattern(pattern, s)
    print(f"testing {pattern=} string {s=}: {res}")

    pattern, s = "abc", "dog cat dog"
    res = sol.wordPattern(pattern, s)
    print(f"testing {pattern=} string {s=}: {res}")



if __name__ == ("__main__"):
    main()
