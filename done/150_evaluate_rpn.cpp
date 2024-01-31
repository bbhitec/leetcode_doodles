/**
    @author [bbht]
    @brief  leetcode series
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
    -basic vector operation
    -cpp function pointers

    @version 2024.01
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <map>
#include <functional>   // usage of function wrapper
using namespace std;


////////////////// DECL_IMPL

// option to use a token-to-function(cpp wrapper) map for operations.
// assisted
//
// sub 70 15
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // [demo][bp] mapping operation token to desired action with functional wrappers
        map<string, function<int(int, int)>> op{
            {"+", [](int x, int y) -> int { return x + y; }},
            {"-", [](int x, int y) -> int { return x - y; }},
            {"*", [](int x, int y) -> int { return x * y; }},
            {"/", [](int x, int y) -> int { return x / y; }}
        };
        vector<int> history;
        for (auto& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                history.push_back(stoi(token));
            } else {
                int oprnd1 = history.back(); history.pop_back();
                int oprnd2 = history.back(); history.pop_back();

                // with the op map, it is easier to call the actions
                history.push_back(op[token](oprnd2, oprnd1));
            }
        }
        return history[0];
    }
};


// have a result array, go over the token list. if its a number, push into the array, if its an operation, pop two latest numbers and push the result of the operation
// return the only remaining member
//
// sub 100 16
class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> history;
        for (auto& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                history.push_back(stoi(token));
            } else {
                int oprnd1 = history.back(); history.pop_back();
                int oprnd2 = history.back(); history.pop_back();

                if (token == "+") history.push_back(oprnd2 + oprnd1);
                if (token == "-") history.push_back(oprnd2 - oprnd1);
                if (token == "*") history.push_back(oprnd2 * oprnd1);
                if (token == "/") history.push_back(oprnd2 / oprnd1);
            }
        }
        return history[0];
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // vector<string> tokens = {"2","1","+","3","*"};
    // vector<string> tokens = {"4","13","5","/","+"};
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<s.evalRPN(tokens)<<endl;

    return 0;
}