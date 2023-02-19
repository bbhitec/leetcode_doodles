##!/usr/bin/env python
'''
    @author [mst]
    @file   206_reverse_linked_list.py
    @brief  leetcode problems series
    206. Reverse Linked List
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    gains:
    -recursive thinking
    -python classes and pointers

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
    # [demo] recursive list reversal
    # submitted with: 25% T 8% S
    def reverseList(self, head: ListNode) -> ListNode:
        # stopping condition. we use next.nxt so we have to check it is valid
        if head is None or head.next is None:
            return head

        # treat rest of list
        rest = self.reverseList(head.next)

        # treat current node
        head.next.next = head
        head.next = None

        return rest


class Solution1:
    # [demo] iterative three-pointer list reversal
    # submitted with: 66% T 55% S
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head

        while curr is not None:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        return prev





################## DRIVER
def main():
    print ("[mst] 206_reverse_linked_list")

    sol = Solution()


    # testing
    case = [1,2,3,4]
    l1 = make_list(case)
    print_list(l1)
    l1r = sol.reverseList(l1)
    print_list(l1r)



if __name__ == ("__main__"):
    main()
