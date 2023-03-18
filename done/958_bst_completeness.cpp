/**
    @author [mst]
    @brief  leetcode problems series
    958_bst_completeness
    Given the root of a binary tree, determine if it is a complete binary tree.
	In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

    gains:
	-tree level-order traversal in cpp

    features, changelog:
    -2023.03:	-initial draft

    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <deque>			// usage of queue for a level-order traversal
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


// level traverse the tree using a queue. once a null (leaf) is detected,
// no valid nodes should be present in the queue
//
// sb: 100 10
class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		deque<TreeNode*> q;
		q.push_front(root);

		while (!q.empty()) {
			TreeNode* node  = q.front();
			q.pop_front();

			if (node) {
				q.push_back(node->left);
				q.push_back(node->right);
			} else {
				// we have reached a null during level order
				// traversal - no more valid nodes expected
				while (!q.empty()) {
					if (q.front()) return false;
					q.pop_front();
				}
			}
		}
        return true;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;
	TreeNode tree1;

	// inserting values as the example shows: [4,2,7,1,3,6,9]
	tree1.insert(1);
	tree1.left = new TreeNode(2);
	tree1.right = new TreeNode(3);
	tree1.left->left = new TreeNode(4);
	tree1.left->right = new TreeNode(5);
	// tree1.right->left = new TreeNode(6);	// uncomment to make false
	tree1.right->right = new TreeNode(7);

	tree1.printInOrder();

	cout << "result: " << endl;
	cout << sol.isCompleteTree(&tree1);

	return 0;
}
