##!/usr/bin/env python
'''
    @author [mst]
    @file   142_list_cycle2.py    
    @brief  leetcode problems series
    142. Linked List Cycle II
    Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
    There is a cycle in a linked list if there is some node in the list that
    can be reached again by continuously following the next pointer.
    Internally, pos is used to denote the index of the node that tail's
    next pointer is connected to (0-indexed). It is -1 if there is no cycle.
    Note that pos is not passed as a parameter.

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

class Solution2:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None:
            return None

        p = head
        while p:
            p2 = p
            while p2:
                p2 = p2.next
                if p == p2:
                    return p.val

            p = p.next
        return None


# simple sliding-window solution
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        
        p = head
        p2 = head
        i = 0

        while (p is not None) and (p2 is not None):
            if p.next:
                p = p.next
            else:
                return None
            if p2.next and p2.next.next:
                p2 = p2.next.next
            else:
                return None
            # i = i + 1
            if p == p2:
                while p2.next != p:
                    p2 = p2.next
                    i = i + 1
                return i


        return None



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
    print ("[mst] 142_list_cycle2")
    
    sol = Solution()
       
    # testing
    list1 = make_list_with_cycle([0,1,2,3], 1)
    # list2 = make_list([1,3,4])
    print(sol.detectCycle(list1))
    # print_list(list3)

    


if __name__ == ("__main__"):
    main()
