/**
    @author [mst]
    @brief  leetcode series
    946_validate_stack_sequence
	Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

    gains:
    -[wip] rd the solution

    @version 0.1 2023.04
*/


////////////////// DECL_IMPL


// using a string builder to add each char or pop the previous one if * is encountered
// can be done with a stacke also
//
// sub 61 48
public class Solution1
{
    public string RemoveStars(string s)
    {
        var builder = new StringBuilder();

        foreach (char c in s.ToCharArray())
        {
            if (c == '*')
            {
                builder.Remove(builder.Length - 1, 1);
            }
            else
            {
                builder.Append(c);
            }
        }
        return builder.ToString();

    }
}

public class Solution
{
    public bool ValidateStackSequences(int[] pushed, int[] popped)
    {
        Stack<int> stk = new Stack<int>();
        int i = 0;
        foreach (int n in pushed)
        {
            stk.Push(n);
            while ((popped[i] == stk.Peek()) && (stk.Count() > 0))
            {
                Console.WriteLine("match!");
                stk.Pop();
                i += 1;
            }
        }

        return (stk.Count() == 0);
    }
}



////////////////// DRIVER

Solution s = new Solution();

int[] pushed = { 1, 2, 3, 4, 5 };
int[] popped = { 4, 5, 3, 2, 1 };

Console.WriteLine(s.ValidateStackSequences(pushed, popped));

