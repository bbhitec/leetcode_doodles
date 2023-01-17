/*
[mst] 226_invert_binary_tree.cpp
leetcode problems series

226. Invert Binary Tree
Example: 
Input : 
    4
   / \
  2   7
 / \  / \
1   3 6  9
Output: 
    4
   / \
  7    2
 / \  / \
9   6 3  1

Gains:
-Binary trees behaviour
-Recursive aproach cpp

features, changelog:
-2021.01: -initial draft
		  -recursive solution submission
*/ 


////////////////// LIBS
#include <iostream>            // usage of console prints
using namespace std;


////////////////// DECL_IMPL

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return false;
    vector<bool> prime(n, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 0; i < sqrt(n); ++i)
      if (prime[i])
        for (int j = i * i; j < n; j += i)
          prime[j] = false;
    return count(begin(prime), end(prime), true);
  }
};


////////////////// DRIVER
int main()
{
	cout << "[mst] 226_invert_binary_tree doodle" << endl << endl;

	TreeNode tree1;

	// inserting values as the example shows: [4,2,7,1,3,6,9]
	tree1.insert(4);
	tree1.insert(2);
	tree1.insert(7);
	tree1.insert(1);
	tree1.insert(3);
	tree1.insert(6);
	tree1.insert(9);
	cout << "inputting: [4,2,7,1,3,6,9]" << endl;
	tree1.printInOrder();

	cout << "inverting..." << endl;
	Solution sol;
	TreeNode* tree2 = sol.invertTree(&tree1);
	tree2->printInOrder();

	cin.get(); // pseudo-pause the console
	return 0;
}
