##!/usr/bin/env python
'''
    @author [mst]
    @file   409_longest_palindrome    
    @brief  leetcode problems series
    409. Longest Palindrome
    
    Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters. 
    Letters are case sensitive, for example, "Aa" is not considered a palindrome here.


    gains:
    -simple py dict usage
    -and counters manipulation

    features, changelog:
    -2022.11: -submission

    @version 0.1 2022.11
'''


# build a bucket histogram of appearances of each letter, then
# every odd count adds 1 palindrome length
# every even part in count adds two logest palindrome options
# sub: 13% S 22% T
class Solution:
    def longestPalindrome(self, s: str) -> int:
        if s is None:
            return 0
        
        buckets = {}
        longest = 0
        middle = 0

        # count each char appearance
        for c in s:
            if c in buckets:
                count = buckets.get(c) + 1
            else:
                count = 1
            buckets.update({c:count})

        # calculate possible palindrome
        for char in buckets.keys():
            if (buckets[char] % 2) == 1:
                middle = 1
            longest = longest + buckets[char]//2

        return longest*2 + middle


# snipped solution, two liner: 66%T 22%S
class Solution0:
    def longestPalindrome(self, s):
        c = collections.Counter(s)
        return sum(v - 1 * (v % 2 != 0) for v in c.values()) + 1 * any(v % 2 != 0 for v in c.values())




################## DRIVER
def main():
    print ("[mst] 409_longest_palindrome")
    
    sol = Solution()

       
    # testing
    print(sol.longestPalindrome("abccccdd"))
    print(sol.longestPalindrome("a"))
    print(sol.longestPalindrome("ccc"))
    

if __name__ == ("__main__"):
    main()
