##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    19_remove_nth_node
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    gains:
    -basic list navigation

    features, changelog:
    -2023.01: -submission

    @version 0.1 2023.01
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

# run two pointers to navigate to the node to delete
#
# sub: 26%T 20%S
class Solution:
    def removeNthFromEnd(self, head: [ListNode], n: int) -> [ListNode]:
        tail = head
        p = head
        b = head

        while tail.next:
            if n>1:                
                n = n-1
            else:
                b = p   # remember prev node
                p = p.next
            tail = tail.next

        # p is the node to delete
        # consider if its the head
        if p == head: return head.next

        b.next = p.next
        return head



################## DRIVER
def main():
    
    sol = Solution()
       
    # testing
    case, n = [1,2,3,4,5], 5
    l1 = make_list(case)
    print_list(l1)
    print (f"{n=}")
    l1r = sol.removeNthFromEnd(l1, n)
    print_list(l1r)
    


if __name__ == ("__main__"):
    main()
