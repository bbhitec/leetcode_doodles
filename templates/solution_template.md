<!-- Titles: Simple and explained solution [Python3][93%T][88%S][mst] -->

# Intuition
Build a bucket histogram of appearances of each letter, sort if by the bunber of appearances then construct an output string by printing char*times_appeared

# Approach
Use a dictionary to hold the histogram where key is char and value is the number of appearances. Once built, sort by value and build a string with given data

# Complexity
- Time complexity:
        - Char appearance histogram: O(n)
        - Sort the histogram by values: O(n*log(n))
        - built she resulting string: O(n)

- Space complexity:
        - O(a) to keep character appearances counts (a is alphabet size)
        - O(n) to sort the histogram
        - O(n) to build the result string
- At time of submission: 66% Time, 49% Space ratings

# Code
```
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
```