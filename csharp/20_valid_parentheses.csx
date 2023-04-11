using System;
using System.Collections.Generic;

/**
    @author [mst]
    @brief  leetcode series
    20_valid_parentheses
	Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

    gains:
    -stack algo thinking
    -dictionary and stack in c#

    @version 0.1 2023.04
*/


////////////////// DECL_IMPL


// using a stack to validate the encountered brackets
//
// sub 11 28
public class Solution
{
    public bool IsValid(string s)
    {
        if (s.Length == 1) return false;  // must have a closing bracket

        Stack<char> closings = new Stack<char>();   // upon an opening bracket, we will push corresponding closing one for a simple resolution check
        IDictionary<char, char> brackets = new Dictionary<char, char>()
            {
                { '(',')' },
                { '[',']' },
                { '{','}' }
            };


        // [demo] the .ToCharArray is for optional formatting but not necessary
        foreach (char c in s.ToCharArray())
        {
            if (brackets.ContainsKey(c))
            {
                closings.Push(brackets[c]);
            }
            else if (closings.Count == 0 || closings.Pop() != c)
            {
                return false;
            }
        }

        return closings.Count == 0; // if the pairs correspond, the stack will be empty
    }
}


////////////////// DRIVER

Solution s = new Solution();

string ex = "()[]}";
Console.WriteLine(s.IsValid(ex));

