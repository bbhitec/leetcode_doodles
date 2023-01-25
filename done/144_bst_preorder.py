##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    144_bst_preorder.py
    Given the root of a binary tree, return the preorder traversal of its nodes' values.

    gains:
    -python tree structure
    -basic tree traversal

    features, changelog:
    -2023.01: -submission

    @version 0.1 2023.01
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
        if self.val == -1:
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

# simple preorder (root first, dfs) traversal
#
# sub: 38%T 95%S
class Solution:
    def preorderTraversal(self, root):
        res = []
        self.dfs(root, res)
        return res

    def dfs(self, root, res):
        if root:
            res.append(root.val)
            self.dfs(root.left, res)
            self.dfs(root.right, res)



################## DRIVER
def main():
    sol = Solution()

    root = []
    # root = [1]
    # root = [1,2,3]

    # testing
    head = TreeNode()
    head.insert_arr(root)
    res = sol.preorderTraversal(head)
    print(f"{root=}, {res=}")






if __name__ == ("__main__"):
    main()
