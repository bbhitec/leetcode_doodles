/**
    @author [mst]
    @brief  leetcode problems series
    101_symmetric_tree
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    gains:
	-algorithmic thinking in tree traversal

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
};


// run recursively double-splitting from the root
//
// sb: 55 24
class Solution {
public:
	bool mirrored (TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) return true;
		if (root1 == nullptr || root2 == nullptr) return false;

		return (root1->val == root2->val)
		&& mirrored (root1->left, root2->right)
		&& mirrored (root1->right, root2->left);
	}

    bool isSymmetric(TreeNode* root) {
		return mirrored(root, root);
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;
	TreeNode tree1;

	// inserting values as the example shows: [4,2,7,1,3,6,9]
	tree1.insert(1);
	tree1.left=new TreeNode(2);
	tree1.insert(2);
	tree1.insert(3);
	tree1.left->left = new TreeNode(3);
	tree1.left->right = new TreeNode(4);
	tree1.right->left = new TreeNode(4);
	tree1.right->right = new TreeNode(3);
	tree1.printInOrder();

	cout << "result: " << endl;
	cout << sol.isSymmetric(&tree1);

	return 0;
}
