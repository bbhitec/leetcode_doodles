##!/usr/bin/env python
'''
    @author [mst]
    @file   100_same_tree
    @brief  leetcode problems series
    100_same_tree
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.
    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    gains:
    -prefix sum approach

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
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

# compare the two trees values recursively
#
# sub: 52%T 27%S
class Solution:
    def isSameTree(self, p: [TreeNode], q: [TreeNode]) -> bool:
        if p == None and q == None: return True
        if p == None and q != None: return False
        if p != None and q == None: return False

        if p.val != q.val: return False
        left = self.isSameTree(p.left,q.left)
        right =  self.isSameTree(p.right,q.right)
        return left and right


################## DRIVER
def main():

    p = [1,2,3]
    q = [1,2,3]

    sol = Solution()
    p_head = TreeNode(p)
    q_head = TreeNode(q)
    # p_head.print_inorder()
    # q_head.print_inorder()
    print(f"trees {p=},{q=} res: {sol.isSameTree(p_head, q_head)=}")


if __name__ == ("__main__"):
    main()
