##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    938_range_sum_bst.py
    Given the root node of a binary search tree and two integers low and high,
    return the sum of values of all nodes with a value in the inclusive range [low, high].
    
    gains:
    -python tree structure
    -basic tree traversal

    features, changelog:
    -2023.01: -submission

    @version 0.1 2022.11
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


# traverse the tree and add the node value if within range
#
# sub: 73%T 50%S
class Solution:
    def rangeSumBST(self, root: [TreeNode], low: int, high: int) -> int:
        if root == None:
            return 0

        adding = 0
        if (root.val <= high) and (root.val >= low):
            adding = root.val

        return self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high) + adding


################## DRIVER
def main():
    sol = Solution()

    # root = [10,5,15,3,7,18]
    # low = 7
    # high = 15

    root = [10,5,15,3,7,13,18,1,6]
    low = 6
    high = 10

    # testing
    head = TreeNode()
    head.insert_arr(root)
    res = sol.rangeSumBST(head, low, high)
    print(f"{root=} {low=}{high=}, res= {res=}")


    
    


if __name__ == ("__main__"):
    main()
