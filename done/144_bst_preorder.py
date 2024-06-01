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
    def __init__(self, val=-1, left=None, right=None):
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
class Solution1:
    def preorderTraversal(self, root):
        res = []
        self.dfs(root, res)
        return res

    def dfs(self, root, res):
        if root:
            res.append(root.val)
            self.dfs(root.left, res)
            self.dfs(root.right, res)


# refresher 2024.05
# summing up all simple traversal types
class Solution:
    def preorderTraversal(self, root):
        res = []
        self.preorder_rec(root, res)
        return res

    def preorder_rec(self, root, res):
        if not root:
            return
        res.append(root.val)
        self.preorder_rec(root.left, res)
        self.preorder_rec(root.right, res)


    def inorderTraversal(self, root):
        res = []
        self.inorder_rec(root, res)
        return res

    def inorder_rec(self, root, res):
        if not root:
            return
        self.inorder_rec(root.left, res)
        res.append(root.val)
        self.inorder_rec(root.right, res)


    def postorderTraversal(self, root):
        res = []
        self.postorder_rec(root, res)
        return res

    def postorder_rec(self, root, res):
        if not root:
            return
        res.append(root.val)
        self.postorder_rec(root.left, res)
        self.postorder_rec(root.right, res)



################## DRIVER
def main():
    sol = Solution()

    # root = []
    # root = [1]
    root = [2,1,3]

    # testing
    head = TreeNode()
    head.insert_arr(root)
    res = sol.preorderTraversal(head)
    print(f"{root=}, {res=}")

    res = sol.inorderTraversal(head)
    print(f"{root=}, {res=}")

    res = sol.postorderTraversal(head)
    print(f"{root=}, {res=}")






if __name__ == ("__main__"):
    main()
