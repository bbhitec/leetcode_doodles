##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    66_plus_one
    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
    Increment the large integer by one and return the resulting array of digits.

    gains:
    -simple py array maipulations
    -modulo basics


    @version 0.1 2023.09.01
'''


# simple carry calculation approach
#
# sub 93 65
#
class Solution:
    def plusOne(self, digits: [int]) -> [int]:
        carry = 1   # initial carry is the plus one
        for d in range(len(digits)-1,-1,-1):
            new = digits[d] + carry
            carry = new // 10
            digits[d] = new % 10
            if d == len(digits)-1 and carry == 0:
                return digits

        if carry:
            digits.insert(0,carry)
        return digits


# shorter, cleaner version
class Solution2:
  def plusOne(self, digits: List[int]) -> List[int]:
    for i, d in reversed(list(enumerate(digits))):
      if d < 9:
        digits[i] += 1
        return digits
      digits[i] = 0

    return [1] + digits

################## DRIVER
def main():
    sol = Solution()

    print (sol.plusOne([9,9,9]))
    print (sol.plusOne([1,2,3]))
    print (sol.plusOne([4,3,2,1]))
    print (sol.plusOne([9]))
    print (sol.plusOne([8,9,9,9]))
    print (sol.plusOne([9,8,9]))



if __name__ == ("__main__"):
    main()
