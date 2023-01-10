##!/usr/bin/env python
'''
    @author [mst]
    @file   938_range_sum_bst.py    
    @brief  leetcode problems series
    938 and cn also be used for 144
    
    
    [wip] python bst tools: insertion, print etc.

    features, changelog:
    -2022.11: -submission

    @version 0.1 2022.11
'''

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

            
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# [demo] assisting function making a linked list out of a python list (array)
def make_list(nums):
    if not nums:
        return None
    
    head = ListNode(nums[0])
    p = head
    for n in nums[1::]:
        new_node = ListNode(n)
        p.next = new_node
        p = p.next

    return head


def print_list(lst : ListNode):
    while lst:
        print(f"{lst.val} -> ", end='')
        lst = lst.next
    print("")


# simple sliding-window solution
#submitted: 5% T 55% S
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head:
            return None
        step = head
        double = head

        while double and double.next:
            double = double.next.next
            step = step.next
        return step



    def append(self, lst: ListNode, value) -> ListNode:
        if not lst:
            return ListNode(value)
        
        p = lst
        while p.next:
            p = p.next
        p.next = ListNode(value)

        return lst



################## DRIVER
def main():
    print ("[mst] 876_middle_of_list")
    
    sol = Solution()
       
    # testing
    list1 = make_list([1,2,3,4,5])
    # list2 = make_list([1,3,4])
    list3 = sol.middleNode(list1)
    print_list(list3)
    


if __name__ == ("__main__"):
    main()
