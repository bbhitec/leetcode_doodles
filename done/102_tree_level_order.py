##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    102_tree_level_order

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


# traverse preorder while keeping the current depth
# and build a hash map of {depth: list of nodes}
#
# sub: 68T 16S
class Solution0:
    def levelOrder(self, root: [TreeNode]) -> [[int]]:

        def traverse_preorder(root, level):
            if root == None: return

            if level in level_wise:
                cur = level_wise.get(level)
                cur.append(root.val)
            else:
                cur = [root.val]
            level_wise.update({level:cur})


            if root.left: traverse_preorder(root.left, level+1)
            if root.right: traverse_preorder(root.right, level+1)

            return


        # dict with key=depth:val=[list of values]
        level_wise = {}

        traverse_preorder(root, level = 0)

        # print(level_wise.values())
        return level_wise.values()


# snipped, iterative solution
#
# sub: 73T 79S
class Solution:
    def levelOrder(self, root: [TreeNode]) -> [[int]]:
        if not root: return

        res, curr_depth = [[root.val]], [root]

        while curr_depth:
            next_depth_nodes, values = [], []
            for node in curr_depth:
                if node.left:
                    next_depth_nodes.append(node.left)
                    values.append(node.left.val)
                if node.right:
                    next_depth_nodes.append(node.right)
                    values.append(node.right.val)
            if next_depth_nodes:
                curr_depth = next_depth_nodes.copy()
                res.append(values)
            else:
                break
        return res

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

    # case: [3,9,20,null,null,15,7]
    p_head = TreeNode(3)
    p_head.left = TreeNode(9)
    p_head.right = TreeNode(20)
    p_head.right.right = TreeNode(7)
    p_head.right.left = TreeNode(15)
    p_head.print_inorder()


    print(f"res: {sol.levelOrder(p_head)=}")


if __name__ == ("__main__"):
    main()
