/**
    @author [mst]
    @brief  leetcode problems series
	141_list_cycle
    Given head, the head of a linked list, determine if the
    linked list has a cycle in it.
    There is a cycle in a linked list if there is some node
    in the list that can be reached again by continuously following
    the next pointer. Internally, pos is used to denote the index of
    the node that tail's next pointer is connected to.
    Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.

    gains:
    -cpp linked list basics

    @version 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

////////////////// DECL_IMPL

////////////////// DECL_IMPL

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// print a list helper method
void printList (ListNode* head) {
    if (head == nullptr) {
        std::cout << "empty list" << std::endl;
        return;
    }

    ListNode* lp = head;
    while (lp) {
        std::cout << lp->val << ',';
        lp = lp->next;
    }

    std::cout << "nullptr" << '\n';
}

// list push helper function
void pushList(ListNode* &head, int val) {
    // [bp] this will still work with an empty list case
    ListNode* NewNode = new ListNode(val, head);
    head = NewNode;
}

// list end insertion helper function
void addTailList(ListNode* &head, int val) {
    //if (head == nulptr) { // [demo] unnecessary check
    //    return
    //}
    ListNode* NewNode = new ListNode(val, nullptr);
    if (head == nullptr) {
        head = NewNode;
        return;
    }

    ListNode* ptr = head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = NewNode;
}

// detecting a cycle using the ususal slow and fast pointers approach
//
// sub: 38t 48s
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while (slow && fast) {
                if (slow->next)
                    slow = slow->next;
                else
                    return false;

                if (fast->next && fast->next->next)
                    fast = fast->next->next;
                else
                    return false;

                if (slow == fast) return true;
            }
        }
        return false;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

    // case 1
    ListNode* l5 = nullptr;
    addTailList (l5,3);
    addTailList (l5,2);
    addTailList (l5,0);
    addTailList (l5,-4);
    cout << "given list..." << endl;
    printList(l5);

    cout << "introducing a cycle and checking..." << endl;
    l5->next->next->next->next = l5->next;
    cout << sol.hasCycle(l5) << endl;

	return 0;
}
