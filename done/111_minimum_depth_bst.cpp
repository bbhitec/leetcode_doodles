/**
    @author [mst]
    @brief  leetcode series
    111_minimum_depth_bst
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

    gains:
    -basic bst traversal

    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <algorithm>     // usage of min
using namespace std;


////////////////// DECL_IMPL

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// basic recursive traversal
//
// sub 40 15
class Solution {
public:
    int minDepth(TreeNode* root) {
        // stopping conditions
        if (root == nullptr) return 0;  // empty bst
        if (root->left == nullptr) return 1 + minDepth(root->right);   // left leaf
        if (root->right == nullptr) return 1 + minDepth(root->left);   // left leaf

        return 1 + min(
            minDepth(root->left),
            minDepth(root->right));
    }
};


////////////////// DRIVER
int main()
{
    Solution s;

    // // sexy init given example [3,9,20,null,null,15,7]
    // TreeNode root(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    // sexy init given example [2,null,3,null,4,null,5,null,6]
    TreeNode root(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4, nullptr, new TreeNode(5, nullptr,new TreeNode(6)))));
    int res = s.minDepth(&root);
    cout << res;


    return 0;
}