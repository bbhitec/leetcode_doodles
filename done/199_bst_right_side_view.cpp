/**
    @author [mst]
    @brief  leetcode series
    199_bst_right_side_view

    gains:
    -cpp recursive orientation
    -[next] introduce iterative (bfs) solution


    @version 2024.02
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


class TreeNode {
private:

public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent; // the parent node is not always available
	TreeNode() : val(-1), left(nullptr), right(nullptr){}	// here invalid value is -1
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}

	void printInOrder(){
		if (left) { left->printInOrder(); }
		cout << val << endl;
		if (right) { right->printInOrder(); }
	}

	// binary search tree insertion (recursive)
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

	// check if a value present in the given (sub)tree
	bool find (int val) {
		TreeNode *root=this;
		if (root == nullptr){
			return false;
		}

		if (root->val == val) return true;
		if (val > root->val) {
			return right->find(val);
		} else {
			return left->find(val);
		}
	}

	// used in leetcode 226, a recursive tree inversion
	TreeNode* invertTree(TreeNode* root){
		// stopping condition: we are at the leaf
		if (root == nullptr){
			return root;
		}

		TreeNode* left = invertTree(root->left);	// this will traverse down to the leaves and keep nodes in the stack for inversion
		TreeNode* right = invertTree(root->right);

		root->left = right;	// the actual re-routing of the nodes
		root->right = left;

		return root;
	}

	// [here] use https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/ to complete
	// In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree.
	// Inorder Successor is NULL for the last node in Inorder traversal.
	// used in leetcode 285 [here] also, consider a version with a parent pointer type of nodes
	int inOrderSuccessor (int val) {
		// reached a leaf (int not found)
		if (this == nullptr) {
			return -1;
		}

		// value found - indicate that spotted
		if (val == this->val) {
			if (this->right) return this->right->val;
			return -2;
		}
		int res;
		if (val > this->val) {
			res = right->inOrderSuccessor(val);
			if (res == -2) return this->val;
			return res;
		} else {
			res = left->inOrderSuccessor(val);
			if (res == -2) return this->val;
			return res;
		}
	}

};

// recursive dfs approach: use a post-order approach while taking
// the first node each time a new depth is reached
// assisted. O(n) time and space
//
// sub 100 27
class Solution {
    // isolate recursion
    void rec(TreeNode* root, int d, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        if (res.size() == d)
            res.push_back(root->val);
        rec(root->right, d+1, res);
        rec(root->left, d+1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int d = 0;

        rec(root, d, res);
        return res;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;


    TreeNode *tree1 = new TreeNode();
    int array[] = {1,3};
    tree1->insert(array,2);
    tree1->left = new TreeNode(2);
    tree1->left->right = new TreeNode(5);
    tree1->right->right = new TreeNode(4);

    tree1->printInOrder();

    vector<int> res = s.rightSideView(tree1);
    for (auto &v: res) cout << v << ", ";

    return 0;
}