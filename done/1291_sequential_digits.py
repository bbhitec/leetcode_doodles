##!/usr/bin/env python
'''
    @author [bbht]
    @brief  leetcode problems series
    1291_sequential_digits
    medium
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

    gains:
    -py queue
    -numbers tricks

    @version 2024.02
'''

# iterate throug possible numbers within range
# assisted
#
# sub 99 63
class Solution:
    def sequentialDigits(self, low: int, high: int) -> [int]:
        res = []
        digits_low = len(str(low))
        digits_high = len(str(high))

        for lengths in range(digits_low, digits_high + 1):
            # no use in checking digits that are cant build the number
            for digit in range(1,(11-lengths)):

                # build a number by the rules
                n = digit
                prev = digit
                for i in range(lengths-1):
                    prev += 1
                    n = n * 10 + prev

                # add if in range
                if low <= n <= high:
                    res.append(n)
        return res


# queue based solution: each possible number is a cycling of the digits in [1,9]
# so whe build all possible combinations until we reach 'high' and add the ones in range
# assisted
#
# sub 55 63
from collections import deque
class Solution2:
    def sequentialDigits(self, low: int, high: int) -> [int]:
        ans = []
        queue = deque(range(1, 10)) # digits from 1 to 9

        while queue:
            n = queue.popleft()
            if n > high:
                return ans
            if low <= n <= high:
                ans.append(n)

            rightmost_digit = n % 10
            if rightmost_digit < 9:
                queue.append(n * 10 + rightmost_digit + 1)
        return ans


################## DRIVER
def main():
    s = Solution()
    print (s.sequentialDigits(low = 100, high = 300))
    print (s.sequentialDigits(low = 1000, high = 13000))

if __name__ == ("__main__"):
    main()
