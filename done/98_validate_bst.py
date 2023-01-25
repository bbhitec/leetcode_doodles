##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    98_validate_bst
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).
    A valid BST is defined as follows:
    -The left subtree of a node contains only nodes with keys less than the node's key.
    -The right subtree of a node contains only nodes with keys greater than the node's key.
    -Both the left and right subtrees must also be binary search trees.

    gains:
    -bst in python
    -algorithmic conversion of bst

    @version 2023.01
'''

################## DECL_IMPL

# Definition for a binary tree node. (taken from leetcode problems)
class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def print_inorder(self):
        if self.left:
            self.left.print_inorder()
        print(f"{self.val} ", end='')
        if self.right:
            self.right.print_inorder()
        return

    # insert single node
    def insert(self, x):
        # empty node insertion
        if self.val == None:
            self.val = x
            return

        # bst insertions
        if x <= self.val:
            if self.left:
                self.left.insert(x)
            else:
                self.left = TreeNode(x)
        else:
            if self.right:
                self.right.insert(x)
            else:
                self.right = TreeNode(x)
        return

    # array to bst
    def insert_arr(self, ar : []):
        if len(ar) == 0: return

        for n in ar:
            self.insert(n)

# assisted
# convert tree to list with an in order traversal then check list
#
# sub 81T 13S
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def tolist(root):
            if root.left:
                tolist(root.left)
            inorderl.append(root.val)
            if root.right:
                tolist(root.right)

        # build an inorder list from the tree
        inorderl=[]
        if root:
            tolist(root)

        # check the list order
        for i in range(1,len(inorderl)):
            if inorderl[i-1]>=inorderl[i]:
                return False
        return True

# this recursive solution got complicated in cases with erroneus mid-tree nodes
class Solution0:
    def isValidBST(self, root: []) -> bool:
        def dfs (root: []) -> bool:
            # reaching the leaf
            if root == None: return True

            #-The left subtree of a node contains only nodes with keys less than the node's key.
            if root.left:
                if root.left.val >= root.val: return False

            #-The right subtree of a node contains only nodes with keys greater than the node's key.
            if root.right:
                if root.right.val <= root.val: return False

            #-Both the left and right subtrees must also be binary search trees.
            return dfs(root.left) and dfs(root.right)

        is_bst = dfs(root)
        return is_bst


################## DRIVER
def main():
    sol = Solution()

    # p = [1,2,3]
    # p = [2,1,3]
    # p_head = TreeNode()
    # p_head.insert_arr(p)
    # p_head.print_inorder()

    # # case: [5,1,4,null,null,3,6]
    # p = [5,1,4,3,6]
    # p_head = TreeNode()
    # p_head.insert_arr([5,1])
    # p_head.right = TreeNode(4)

    # # case: [2,2,2]
    # p_head = TreeNode()
    # p_head.insert_arr([2,2])

    # case: [5,4,6,null,null,3,7]
    p_head = TreeNode()
    p_head.insert_arr([5,4,6,7])
    p_head.right.left = TreeNode(3)


    print(f"res: {sol.isValidBST(p_head)=}")


if __name__ == ("__main__"):
    main()
