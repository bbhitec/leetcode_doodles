/**
    @author [mst]
    @brief  leetcode problems series
    700_search_bst
    You are given the root of a binary search tree (BST) and an integer val.
	Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

    gains:
	-basic trees/bst in cpp

    features, changelog:
    -2023.01:	-initial draft

    @version 0.1 2023.01
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

// traverse the tree (in-order) in relation to the bst order
//
// sub: 61%T 33%S
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;

        if (root->val == val) return root;
        if (val < root->val) {
            return searchBST(root->left,val);
        }
        else {
            return searchBST(root->right,val);
        }
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
	TreeNode* res = sol.searchBST(&tree1, 5);
	cout << "result: " << res->val;


	cin.get(); // pseudo-pause the console
	return 0;
}
