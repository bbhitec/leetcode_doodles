##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    49_group_anagrams
    Given an array of strings strs, group the anagrams together.
    You can return the answer in any order.
    An Anagram is a word or phrase formed by rearranging
    the letters of a different word or phrase, typically using all the original letters exactly once.

    gains:
    -py strings, sorting and hashmaps (dictionaries)


    @version 2024.02
'''

# hash table approach: sort each string and see if it is a key in the hash table.
# if its in it, add the original string to an array of this key, otherwise create a ney key-value
# with the original string as the value. Finally return the values of the map
#
# sub 68 83
class Solution:
    def groupAnagrams(self, strs: [str]) -> [[str]]:
        if not strs:
            return [[]]

        res = {}
        for s in strs:
            key = ''.join(sorted(s))
            if key in res:
                res[key].append(s)
            else:
                res.update({key : [s]})

        # print(res.values())
        return res.values()


from collections import defaultdict

# same, but a more elegant implementation
class Solution2:
    def groupAnagrams(self, strs: [str]) -> [[str]]:
        res = defaultdict(list)

        for str in strs:
            key = ''.join(sorted(str))
            res[key].append(str)

        return res.values()


################## DRIVER
def main():
    sol = Solution()

    strs = ["eat","tea","tan","ate","nat","bat"]
    res = sol.groupAnagrams(strs)
    print (res)


if __name__ == ("__main__"):
    main()
