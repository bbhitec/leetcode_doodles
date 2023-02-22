##!/usr/bin/env python
'''
    @author [mst]
    @file   21_merge_lists.py
    @brief  leetcode problems series
    21. Merge Two Sorted Lists
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.

    features, changelog:
    -2022.11: -submission

    @version 0.1 2022.11
'''

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

class Solution:
    def __init__(self):
        self.l3 = None

    # walk two pointers over both lists always appending minimal value to the result list
    # initial submission: 75% T 80% S
    # note: using l3 as a class variable yielded 5% T
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        if not list1:
            return list2
        if not list2:
            return list1
        # if both are null we will return null

        l1 = list1
        l2 = list2
        l3 = None

        while l1 and l2:
            if l1.val < l2.val:
                l3 = self.append(l3,l1.val)
                l1 = l1.next
            else:
                l3 = self.append(l3,l2.val)
                l2 = l2.next

        if l1:
            leftover = l1
        if l2:
            leftover = l2
        while(leftover):
            l3 = self.append(l3, leftover.val)
            leftover = leftover.next

        return l3

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
    print ("[mst] 21_merge_lists")

    sol = Solution()

    # testing
    list1 = make_list([1,2,4])
    list2 = make_list([1,3,4])
    list3 = sol.mergeTwoLists(list1, list2)
    print_list(list3)



if __name__ == ("__main__"):
    main()
