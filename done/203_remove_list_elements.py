##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    203_remove_list_elements

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



# snipped solution
class Solution2:
    def removeElements(self, head: [ListNode], val: int) -> [ListNode]:
        #check base case
        if(head==None):
            return head

       #assign head to temp head and prev_head
        temp_head = head
        prev_head = head

        #traverse through the link list till end of list
        while(temp_head):
            #check if current value is equal to the value which we want to delete
            if(temp_head.val == val ):
                #check if it is first element or not
                if(temp_head == prev_head):
                    #if first element then head and prev_head both will assign to next of current node
                    head = head.next
                    prev_head = prev_head.next
                else:
                    #Unlink the node from linked list
                    prev_head.next =  temp_head.next
            else:
                #if it is not first node then prev_head to prev_head.next
                if(temp_head!=prev_head):
                    prev_head = prev_head.next
            #change temp_head to temp_head.next
            temp_head = temp_head.next
        return head


# this solution didn't handle a null-head
class Solution0:
    def removeElements(self, head: [], val: int) -> []:
        if head.val == val:
            head = head.next
            return

        prev = head
        curr = head.next

        while curr is not None:
            if curr.val == val:
                # the actual deletion (omission),
                # we can return here if only a single deletion is required
                prev.next = curr.next
                # return
            else:
                prev = curr
            curr = curr.next
        return head

class Solution:
    def removeElements(self, head: [], val: int) -> []:
        if head == None:
            return head

        # if head.val == val:
        #     return head.next


        prev = head
        curr = head

        while curr is not None:
            if curr.val == val:
                # the actual deletion (omission),
                # we can return here if only a single deletion is required
                prev.next = curr.next
                # return
            else:
                prev = curr
            curr = curr.next
        return head

# another snipped one, simple
#
# sub: 99%T 37%S
class Solution1:
    def removeElements(self, head, val):
        # first loop - remove matching nodes from head of list
        while head and head.val == val:
            head = head.next

        current = head

        # second loop - iterate whgile cutting upcoming matches
        while current:
            while current and current.next and current.next.val == val:
                current.next = current.next.next
            current = current.next
        return head


################## DRIVER
def main():

    sol = Solution1()

    # testing
    case, val = [1,2,6,3,4,5,6], 6
    # case, val = [], 1
    # case, val = [7,7,7], 7
    l1 = make_list(case)
    print_list(l1)
    print (f"{val=}")
    l1r = sol.removeElements(l1, val)
    print_list(l1r)



if __name__ == ("__main__"):
    main()
