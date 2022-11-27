'''
 [mst] 32_valid_parentheses.py
 32. Longest Valid Parentheses
 Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring

 gains:
 - algo thinking
 - python vectors and pairs
	
 log
 - 2022.11.27: submission 16% T 7% S
 - 2022.11: initial

Created on Nov, 2022
@author: mst
'''


# stack based ranges solution: use a stack to check parentheses validity the usual way, but save the indices of illegal brackets
# once the whole input is traversed, the stack will have the indices where the order is broken. we calculate the longest gap between these
# note that the last segment may be the longest one and should be checked in the end
# initial submission: 5% time, 5% space (16% t 7% space with no prints)
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # print(f"-->testing string \'{s}\'...")
        if len(s) is 0:
            return 0

        # indices of illigal characters
        stack= []
        max_legal = 0

        for i,c in enumerate(s):
            # print(f"reading index {i}: \'{c}\'... ")

            # we pop pairs but keep illegal brackets in
            if (stack) and (c is ')') and (stack[-1][1] == '('):
                # print(f"popping {stack.pop()}")
                stack.pop()
            else:
                # keep index of opened brackets
                # print(f"pushing {i}")
                stack.append((i,c))

        # print (f"final stack: {stack}")

        # if all the string was legal, it is the maximal legal length
        if (not stack):
            return len(s)

        #find the largest dist between illegal chars
        idx = -1
        for pair in stack:
            range = pair[0] - idx -1
            max_legal = max(max_legal,range)
            idx = pair[0]
        
        # final segment
        range = len(s) - idx -1
        max_legal = max(max_legal,range)

        return max_legal
        
# driver
def main():
    print ("[mst] 32_longest_valid_parentheses")
    
    sol = Solution()
        
    # testing
    case0 = ""
    case1 = ")()())"    
    case2 = ")()())()"
    case3 = ")()())()()()()()()()()"

    case = case3
    print (f"checking {case}: {sol.longestValidParentheses(case)}")


# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main() 