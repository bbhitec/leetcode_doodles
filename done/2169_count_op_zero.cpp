/**
    @author [mst]
    @file   2169_count_op_zero.cpp
    @brief  title or quick description
    Given two non-negative integers num1 and num2.
    In one operation, if num1 >= num2, you must subtract num2 from num1, otherwise subtract num1 from num2.
    For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus obtaining num1 = 1 and num2 = 4. However, if num1 = 4 and num2 = 5, after one operation, num1 = 4 and num2 = 1.
    Return the number of operations required to make either num1 = 0 or num2 = 0.
    0 <= num1, num2 <= 105

    Gains:
    -algorithms: recursive calls

    features, changelog:
    -2021.04: -initial draft. accepted with 8.28% faster 6.52% less memory

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints


////////////////// DECL_IMPL

/**
     * [mst] initial solution, a recursive calls
     */
class Solution {    
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0) return 0;

        if (num1 > num2) return (1 + countOperations(num1-num2, num2));
        else return (1 + countOperations(num1, num2-num1));
    }
};


////////////////// DRIVER
int main()
{
    using namespace std;    
	cout << "[mst] leetcode 2169. Count Operations to Obtain Zero" << '\n' << '\n';

    Solution sol1;
    int num1 = 5;
    int num2 = 4;
    cout << "case 0. num1: " << num1 << " num2: " << num2 << " sol: " << sol1.countOperations(num1, num2) << endl;

    num1 = num2 = 10;
    cout << "case 0. num1: " << num1 << " num2: " << num2 << " sol: " << sol1.countOperations(num1, num2) << endl;

    num1 = 2;
    num2 = 3;
    cout << "case 0. num1: " << num1 << " num2: " << num2 << " sol: " << sol1.countOperations(num1, num2) << endl;

	//cin.get(); // pseudo-pause the console
	return 0;
}
