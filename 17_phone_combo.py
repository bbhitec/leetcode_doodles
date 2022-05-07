
"""
 [mst] 17_phone_combo.py 
 leetcode problems series
    17. Letter Combinations of a Phone Number
    Given a string containing digits from 2-9 inclusive, return all possible
    letter combinations that the number could represent. Return the answer
    in any order.
    Note that 1 does not map to any letters.
    
    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 log
 -initial
 -2021.01: -used an iterating ASCII index for digit mapping.
            instead, add a hash set to streamline digit-to-letter mapping
           -up-leveled some  class members to omit the 'self' directive
 -[wip] iterative solution is using two cases, where the combinations list
   is empty and one where it is populated. combine this
 -[wip] run a recursive solution option?

Created on Jan 11, 2021
    @author: mst
"""

# my first solution
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        # this will map each digit to iterate-able letters array
        key_map = {
            '2': ['a','b','c'],
            '3': ['d','e','f'],
            '4': ['g','h','i'],
            '5': ['j','k','l'],
            '6': ['m','n','o'],
            '7': ['p','q','r','s'],
            '8': ['t','u','v'],
            '9': ['w','x','y','z']}
            
        combinations_list = []
        
        def expandCombinations(given_list, new_digit):         
            res = []

            # a new combinations list will get just the new combinations
            # [wip] combine these  
            if given_list == []:   
                for letter in key_map[new_digit]:
                    res.append(letter)
            else:
                for member in given_list:
                    for letter in key_map[new_digit]:
                        res.append(member + letter)
            return res

        # basic input check
        # on a length limit we can either return nullor cut the input to size
        if (len(digits)>4): 
            digits = digits[0:4]
            #return combinations_list
        if '1' in digits or '0' in digits:
            return combinations_list

        # iterate for each digit
        for d in digits:
            # extend the possible combinations list with the new chars
            combinations_list = expandCombinations(combinations_list,  d)
            
  
        return combinations_list

# recursive solution. not mine 
# [wip] implement my own and go over it
class Solution2(object):
    def letterCombinations(self, digits):
        '''
        :type digits: str
        :rtype: List[str]
        '''
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}    
        result = []
        
        def helpCombine(current, leftoverDigits):
            if not leftoverDigits:
                result.append(current)
                return 
            else:
                for char in phone[leftoverDigits[0]]:
                    helpCombine(current + char, leftoverDigits[1:])
        
        if not digits:
            return []
        else: 
            helpCombine("", digits)
            return result


# driver
def main():
    print ("[mst] leetcode 17. Letter Combinations of a Phone Number")
    
    sol = Solution()
    
    # case1
    inputs = "23"    
    print("input: " + inputs + ", result: ")
    print(sol.letterCombinations(inputs))
    
    # case2
    inputs = "7"    
    print("input: " + inputs + ", result: ")
    print(sol.letterCombinations(inputs))
    
    # case3
    inputs = "8"    
    print("input: " + inputs + ", result: ")
    print(sol.letterCombinations(inputs))
    
    # case3
    inputs = "9"    
    print("input: " + inputs + ", result: ")
    print(sol.letterCombinations(inputs))
    
    # case4
    inputs = "7232"    
    print("input: " + inputs + ", result: ")
    print(sol.letterCombinations(inputs))
    
    sol2 = Solution2()
    inputs = "7232"    
    print("input: " + inputs + ", result: ")
    print(sol2.letterCombinations(inputs))


# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()       