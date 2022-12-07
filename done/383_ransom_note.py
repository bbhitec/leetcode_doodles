##!/usr/bin/env python
'''
    @author [mst]
    @file   383_ransom_note.py    
    @brief  leetcode problems series
    383. Ransom Note
    Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
    Each letter in magazine can only be used once in ransomNote.

    gains:
    -py3 dictionary
    -vocabilary checking

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''



# build an occurence table of the available letters and
# then run the note to see if characters are available
#
# sub: 90%T 54%S
class Solution(object):
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # no need to check if not enough letters available
        # adding this dropped sub: 37%T 20%S
        if len (magazine) < len (ransomNote):
            return False

        vocabulary_hash = {}

        # build occurence table
        for letter in magazine:
            if letter in vocabulary_hash:
                vocabulary_hash[letter] = vocabulary_hash[letter] + 1
            else:
                vocabulary_hash[letter] = 1

        # check if the note can be built
        for letter in ransomNote:
            if letter in vocabulary_hash and vocabulary_hash[letter] > 0:
                vocabulary_hash[letter] = vocabulary_hash[letter] - 1
            else:
                return False

        # if we're here, the note was built successfully
        return True


# driver
def main():

    s = Solution()

    ransomNote = "a"
    magazine = "b"
    print(f"{ransomNote}, {magazine}: {s.canConstruct(ransomNote,magazine)}")

    ransomNote = "aa"
    magazine = "ab"
    print(f"{ransomNote}, {magazine}: {s.canConstruct(ransomNote,magazine)}")

    ransomNote = "aa"
    magazine = "aab"
    print(f"{ransomNote}, {magazine}: {s.canConstruct(ransomNote,magazine)}")


# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()
    
        