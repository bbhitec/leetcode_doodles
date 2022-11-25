'''
 [mst] 20_valid_parentheses.py 
 leetcode problems series
    20. Valid Parentheses
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if:
    -Open brackets must be closed by the same type of brackets.
    -Open brackets must be closed in the correct order.
    -Every close bracket has a corresponding open bracket of the same type.

 gains:
 - algorithmic thinking
 - python basic data types
	
 log
 - 2022.11: initial

Created on Nov, 2022
@author: mst
'''

# initial solution: 13% time, 26% space
# classic idea is to save a stack of opening brackets that will keep the order:
# each time a closing bracket is met, we pop the stack and check validity
class Solution:
    def isValid(self, s: str) -> bool:
        print(f"-->testing string {s}...")
        if len(s) is 1:
            return False

        # [demo] same as declaring: openings = {'(':')','[':']','{':'}'}
        openings = dict(('()', '[]', '{}'))
        stack = []

        for c in s:
            print(f"reading \'{c}\'... ")
            if c in openings:
                stack.append(c)
                print ("pushing opening bracket")
            else:
                if (len(stack)) is 0:
                    return False
                else:
                    p = stack.pop()
                    print (f"popping \'{p}\'...")
                    if ( c == openings[p] ):
                        print ("order preserved!")                        
                    else:
                        print ("order violated!")
                        return False

        if len(stack) is 0:
            return True
        return False

# solution from leetcode. same ide cleaner syntax 25% time 72% space
# I think the condition to pop is saving resources
class Solution2:
    def isValid(self, s: str) -> bool:
        if len(s) is 1:
            return False
        stack = []
        closeToOpen = {')':'(',']':'[','}':'{'}

        for c in s:
            if c in closeToOpen:
                # [demo] stack[-1] is the top element
                if stack and stack[-1] == closeToOpen[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return True if not stack else False


# driver
def main():
    print ("[mst] 20_valid_parentheses")
    
    sol = Solution()
    sol2 = Solution2()

    opcl = dict(('()', '[]', '{}'))
    print(opcl)
        
    # testing
    print (sol.isValid("("))
    print (sol.isValid("()"))
    print (sol2.isValid("()[]{}"))
    print (sol2.isValid("(]"))


# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main() 