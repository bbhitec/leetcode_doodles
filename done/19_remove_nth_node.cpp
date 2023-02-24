/**
    @author [mst]
    @brief  leetcode problems series
	19_remove_nth_node
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    gains:
    -basic list operations

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

// run to the tail , wait n steps and run a pointer to the node to delete
// sub: 45t 30s
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head) {
            ListNode* tail = head;
            ListNode* del = head;
            ListNode* prev;

            while (tail->next) {
                // count n-1 delay
                if (n>1) n--;
                else {
                    prev = del;
                    del = del->next;
                }
                tail = tail->next;
            }

            // consider the if target is the head
            if (del == head) return head->next;

            // the deletion
            prev->next = del->next;
        }
        return head;
    }
};



////////////////// DRIVER
int main()
{
	Solution sol;

    ListNode* l5 = nullptr;
    addTailList (l5,1);
    addTailList (l5,2);
    addTailList (l5,3);
    addTailList (l5,4);
    addTailList (l5,5);

    printList(l5);
    ListNode* l6 = sol.removeNthFromEnd(l5, 2);
    cout << "after removal:" << endl;
    printList(l6);

	return 0;
}
