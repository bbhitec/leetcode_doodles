/*
[mst] 938_range_sum_bst.cpp
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Gains:
-Binary trees behaviour
-Recursive aproach cpp

features, changelog:
-2022.12: -initial draft
		  -recursive solution submission
*/ 


////////////////// LIBS
#include <iostream>            // usage of console prints
using namespace std;


////////////////// DECL_IMPL

class TreeNode {
private:
	
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(-1), left(nullptr), right(nullptr){}	// here invalid value is -1
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}

	void printInOrder(){
		if (left) { left->printInOrder(); }
		cout << val << endl;
		if (right) { right->printInOrder(); }
	}

	// binary search tree insertion
	void insert(int x) {
		// empty tree case
		if (val == -1) {
			val = x;
			return;
		}
		
		if (x <= val) {	// value lesser than the root will be routed left
			if (left == nullptr){ left = new TreeNode(x); }	// empty left node
			else {
				left->insert(x);	// non empty left node
			}
		}
		else {	// value higherr than the root will be routed right
			if (right == nullptr){ right = new TreeNode(x); }	// empty right node
			else {
				right->insert(x);	// non empty right node
			}			
		}
	}

	// insertion overloaded for array-to-tree conversion
	void insert(int arr[], int size) {
		if (size == 0) return;
		for(int i = 0; i<size; i++) {
			this->insert(arr[i]);
		}
	}
};

// traverse the tree in-order and add the node value if within range
//
// sub: 82%T 60%S
class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr){
			return 0;
		}

		int to_add = 0;
		if ((root->val <= high) && (root->val >= low)) to_add = root->val;

		return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + to_add;
    }

};


////////////////// DRIVER
int main()
{
	TreeNode tree1;

	int array[6] = {10,5,15,3,7,18};
	tree1.insert(array,6);
	tree1.printInOrder();

	Solution sol;
	cout << "result: " << sol.rangeSumBST(&tree1, 7, 15);

	cin.get(); // pseudo-pause the console
	return 0;
}
