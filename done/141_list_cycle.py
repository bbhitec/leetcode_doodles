##!/usr/bin/env python
'''
    @author [mst]
    @file   141_list_cycle.py    
    @brief  leetcode problems series

    based on the slightly harder 142 problem

    gains:
    -cycle algorithmic solving
    -sliding window technique

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
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

# [demo] assisting function making a linked list out of a python list (array)
def make_list_with_cycle(nums, pos):
    if not nums:
        return None
    
    head = ListNode(nums[0])
    p = head
    for n in nums[1::]:
        new_node = ListNode(n)
        p.next = new_node
        p = p.next

    if pos is not -1:
        cyc = head
        while pos is not 0:
            cyc = cyc.next
            pos = pos - 1
        p.next = cyc

    print ("made a list with cycle")

    return head


def print_list(lst : ListNode):
    while lst:
        print(f"{lst.val} -> ", end='')
        lst = lst.next
    print("")




# simple sliding-window solution:
# we first run a slow and a fast pointers to detect a cycle
# note: any None (nullptr) reference would mean an end of a list and so a lack of a cycle
# once the cycle node is spotted, we run a pointer out of a head of the list to spot the cycle entry
# 63% T 61 S
class Solution:
    def hasCycle(self, head: [ListNode]) -> bool:
        if head is None:
            return False
        
        slow = head
        fast = head

        while (slow is not None) and (fast is not None):
            if slow.next:
                slow = slow.next
            else:
                return False
            if fast.next and fast.next.next:
                fast = fast.next.next
            else:
                return False
            if slow == fast:
                return True
                
        return False



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
    
    sol = Solution()
       
    # testing
    list1 = make_list_with_cycle([0,1,2,3], 1)
    # list2 = make_list([1,3,4])
    print(sol.hasCycle(list1))
    # print_list(list3)

    


if __name__ == ("__main__"):
    main()
