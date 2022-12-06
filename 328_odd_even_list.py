##!/usr/bin/env python
'''
    @author [mst]
    @file   328_odd_even_list.py    
    @brief  leetcode problems series
    328. Odd Even Linked List
    Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
    The first node is considered odd, and the second node is even, and so on.
    Note that the relative order inside both the even and odd groups should remain as it was in the input.
    You must solve the problem in O(1) extra space complexity and O(n) time complexity.

    gains:

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


def print_list(lst : ListNode):
    while lst:
        print(f"{lst.val} -> ", end='')
        lst = lst.next
    print("")

class Solution0:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None:
            return None

        
        even_head = head
        if (head.next is not None): odd_head = head.next
        odd = odd_head
        even = even_head
        i = 0

        while head is not None:
            if i % 1 == 0:
                even.next = head
                if (head.next is not None): even = even.next
        return even_head


# snipped from solutions :(
#
# sub: 
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
            
        currentOdd = head
        count = 2
        node = head
        pre = node
        node = node.next
        while node is not None:
            if count % 2 == 0:
                pre = node
                node = node.next
            else:
                next = node.next
                pre.next = next
                temp = currentOdd.next
                currentOdd.next = node
                node.next = temp
                currentOdd = node
                node = next
            count += 1
        return head

################## DRIVER
def main():
    print ("[mst] 328. Odd Even Linked List")
    
    sol = Solution()

       
    # testing
    case = [1,2,3,4,5]
    l1 = make_list(case)
    print_list(l1)
    l1r = sol.oddEvenList(l1)
    print_list(l1r)
    


if __name__ == ("__main__"):
    main()
