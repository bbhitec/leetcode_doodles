// package done;

/**
    @author [bbht]
    @brief  leetcode problems series
    150_evaluate_rpn
    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
    Evaluate the expression. Return an integer that represents the value of the expression.
    Note that:
    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

    gains:
    -basic java map and array handling
    -map of anonymous functions

    @version 2023.02
 **/

////////////////// LIBS
//import java.util.Scanner;
import java.util.Map;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.function.BinaryOperator;

////////////////// DECL_IMPL

// have a result array, go over the token list. if its a number, push into the array
// if its an operation, pop two latest numbers and push the result of the operation
// return the only remaining member
class Solution150 {
    public int evalRPN(String[] tokens) {
        // [demo] map of anonymous/lambda/arrow functions
        final Map<String, BinaryOperator<Integer>> op = Map.of(
                "+", (a, b) -> a + b,
                "-", (a, b) -> a - b,
                "*", (a, b) -> a * b,
                "/", (a, b) -> a / b);
        Deque<Integer> stack = new ArrayDeque<>();

        for (final String token : tokens)
            if (op.containsKey(token)) {
                Integer b = stack.pop();
                Integer a = stack.pop();
                stack.push(op.get(token).apply(a, b));
            } else {
                stack.push(Integer.parseInt(token));
            }

        return stack.pop().intValue();
    }
}

class Driver {
    public static void main(String[] args) {
        System.out.println("[mst] leetcode doodles");

        Solution150 s = new Solution150();

        String[] tokens = { "2", "1", "+", "3", "*" };
        Integer res = s.evalRPN(tokens);

        System.out.printf("result for: %d", res);
    }

}
