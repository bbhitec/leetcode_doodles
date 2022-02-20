'''
 [mst] 2_add_two_nums
 leetcode problems series

 You are given two non-empty linked lists representing two non-negative
 integers. The digits are stored in reverse order, and each of their nodes
 contains a single digit. Add the two numbers and return the sum as a linked
 list. You may assume the two numbers do not contain any leading zero,
 except the number 0 itself.

 log:
 -2021.01: -initial draft
           -another item
 -2020.12: [wip] indicate miscompletion

Created on Jan 11, 2021
@author: mst
'''


## Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        lr = []

        # [wip] naive lists adding
        # [demo] handle different-length lists... [here]
        for i in range(max(len(l1),len(l2))):   
            res = res + carry
            if (i<min(len(l1),len(l2))) :
                res = l1[i] + l2[i] + carry
            elif:
                res = 
            if (res > 9):
                carry = res // 10
                res = res % 10
            lr.append(res)
        
        while (i<maxlen(l1),len(l2)) :
            lr.append()
        return lr


################## DRIVER
def main():
    print ("[mst] leetcode 2. Add Two Numbers")


    # Input: l1 = [2,4,3], l2 = [5,6,4]
    # Output: [7,0,8]
    # Explanation: 342 + 465 = 807.
    l1 = [2,4,3]
    l2 = [5,6,4]
    carry = 0

    print ("summing: ", l1, "and", l2)
    #print ("zipping: ", zip(l1, l2))
    s = Solution()
    result = s.addTwoNumbers(l1, l2)
    print (result)

    l3 = [9,9,9,9,9,9,9]
    l4 = [9,9,9,9]
    print ("summing: ", l3, "and", l4)
    result = s.addTwoNumbers(l3, l4)
    print (result)
    
    
    
    # # [wip] solving using list comprehension?
    # res_lt = [ l1[x] + l2[x] for x in range (len (l1))]
    # print ("comprehention: ", res_lt)


    


   
if __name__ == ("__main__"):
    main() 
