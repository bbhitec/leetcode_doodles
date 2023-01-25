##!/usr/bin/env python
'''
    @author [mst]
    @file   451_sort_char_by_freq
    @brief  leetcode problems series
    451. Sort Characters By Frequency

    Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
    Return the sorted string. If there are multiple answers, return any of them.

    gains:
    -py3 dictionaries, sort by value

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# simply built a char appearance histogram: O(n)
# sort the histogram by values: O(n)
# build the resulting string: O(n)
# sub: 66%T 49%S
class Solution:
    def frequencySort(self, s: str) -> str:
        if s is None:
            return 0

        buckets = {}
        output = ""

        # count each char appearance
        for c in s:
            if c in buckets:
                count = buckets.get(c) + 1
            else:
                count = 1
            buckets.update({c:count})

        sorted_buckets = sorted(buckets.items(), key=lambda x:x[1], reverse=True)
        for pair in sorted_buckets:
            output = output + (pair[0] * pair[1])

        return output






################## DRIVER
def main():
    print ("[mst] 451_sort_char_by_freq")

    sol = Solution()


    # testing
    print(sol.frequencySort("tree"))
    print(sol.frequencySort("cccaaa"))
    print(sol.frequencySort("Aabb"))


if __name__ == ("__main__"):
    main()
