/**
    @author [mst]
    @brief  leetcode problems series
    106_binary_tree_from_inpostorder
    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

    gains:
	-

    features, changelog:
    -2023.03:	-initial draft

    @version 0.1 2023.03
*/


////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>			// usage of queue for a level-order traversal
#include <unordered_map>
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


// snipped: recurse and snip the last member of the postorder array and its relevant neighbors in the in-order array
//
// sub: 80t 25s
class Solution {
public:
	TreeNode *buildTree(vector<int> & inorder, vector<int> & postorder)	{
		unordered_map<int, int> inToIndex;

		for (int i = 0; i < inorder.size(); ++i)
			inToIndex[inorder[i]] = i;

		return build(inorder, 0, inorder.size() - 1, postorder, 0,
						postorder.size() - 1, inToIndex);
	}

private:
	TreeNode *build(const vector<int> &inorder, int inStart, int inEnd,
					const vector<int> &postorder, int postStart, int postEnd,
					const unordered_map<int, int> &inToIndex) {
		if (inStart > inEnd)
			return nullptr;

		const int rootVal = postorder[postEnd];
		const int rootInIndex = inToIndex.at(rootVal);
		const int leftSize = rootInIndex - inStart;

		TreeNode *root = new TreeNode(rootVal);
		root->left = build(inorder, inStart, rootInIndex - 1, postorder, postStart,
							postStart + leftSize - 1, inToIndex);
		root->right = build(inorder, rootInIndex + 1, inEnd, postorder,
							postStart + leftSize, postEnd - 1, inToIndex);
		return root;
	}
};


////////////////// DRIVER
int main()
{
	Solution sol;

	vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
	TreeNode* tree1 = sol.buildTree(inorder,postorder);

	cout << "result: " << endl;
	tree1->printInOrder();

	return 0;
}
