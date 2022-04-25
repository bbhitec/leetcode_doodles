#!/usr/bin/env python
"""
 [mst] 2_add_two_nums
 leetcode problems series

 You are given two non-empty linked lists representing two non-negative
 integers. The digits are stored in reverse order, and each of their nodes
 contains a single digit. Add the two numbers and return the sum as a linked
 list. You may assume the two numbers do not contain any leading zero,
 except the number 0 itself.
 tip for different length lists: https://www.youtube.com/shorts/_1Epl1HdrMI

 log:
 -2022.04 tinketed version. not submitted. used plain python lists
    [wip] a good excersize could be solving with comprehensions

    @author: mst
"""

## Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1,  l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        lres = []
        i = 0

        # [bp] use zip function to handle different length lists
        # the zip won't work on uniterative classes
        for n1, n2 in zip(l1,l2):
            res = n1 + n2 + carry
            carry = res // 10
            res = res % 10
            lres.append(res)
            i = i + 1       # note position

        # add any remaining list tails
        lrem = l1 if len(l1)>len(l2) else l2
        while (i < len(lrem)):
            res = lrem[i] + carry
            carry = res // 10
            res = res % 10
            lres.append(res)
            i = i + 1

        if (carry > 0):
            lres.append(carry)

        return lres


################## DRIVER
def main():
    print ("[mst] leetcode 2. Add Two Numbers")


    # Input: l1 = [2,4,3], l2 = [5,6,4]
    # Output: [7,0,8]
    # Explanation: 342 + 465 = 807.
    l1 = [2,4,3]
    l2 = [5,6,4]

    print ("summing: ", l1, "and", l2)
    s = Solution()
    result = s.addTwoNumbers(l1, l2)
    print (result)

    l4 = [9,9,9,9,9,9,9]
    l3 = [9,9,9,9]
    print ("summing: ", l3, "and", l4)
    result = s.addTwoNumbers(l3, l4)
    print (result)

   
if __name__ == ("__main__"):
    main() 
