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

    gains:
    -cycle algorithmic solving
    -sliding window technique
    -cycle case prep

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

def append(self, lst: ListNode, value) -> ListNode:
        if not lst:
            return ListNode(value)

        p = lst
        while p.next:
            p = p.next
        p.next = ListNode(value)

        return lst





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



# simple sliding-window solution:
# we first run a slow and a fast pointers to detect a cycle
# note: any None (nullptr) reference would mean an end of a list and so a lack of a cycle
# once the cycle node is spotted, we run a pointer out of a head of the list to spot the cycle entry
# 63% T 61 S
class Solution2:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None:
            return None

        slow = head
        fast = head
        entry = head # the node where the cycle begins (where the tail's next is pointing)
        i = 0       # index of cycle start

        while (slow is not None) and (fast is not None):
            if slow.next:
                slow = slow.next
            else:
                return None
            if fast.next and fast.next.next:
                fast = fast.next.next
            else:
                return None
            if slow == fast:
                while slow != entry:
                    slow = slow.next
                    entry = entry.next
                    i = i + 1   # we can return either the node or the index
                return i

        return None




################## DRIVER
def main():
    print ("[mst] 142_list_cycle2")

    sol = Solution()

    # testing
    list1 = make_list_with_cycle([0,1,2,3,4,5], 2)
    #print_list(list1)   # default printing func will infinite loop

    print(sol.detectCycle(list1))




if __name__ == ("__main__"):
    main()
