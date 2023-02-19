##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    94_tree_inorder
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    gains:
    -basic tree traversal in python

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

# basic recursive inorder traversal
#
# sub 55t 95s
class Solution:
    def inorderTraversal(self, root: [TreeNode]) -> [int]:
        def inorder(root):
            if root is None: return None

            # left
            inorder(root.left)

            # root
            res.append(root.val)

            # right
            inorder(root.right)

        res = []
        inorder(root)

        return res



################## DRIVER
def main():
    sol = Solution()

    root = [1,2,3]
    p_head = TreeNode()
    p_head.insert_arr(root)
    p_head.print_inorder()

    print(f"res: {sol.inorderTraversal(p_head)=}")


if __name__ == ("__main__"):
    main()
