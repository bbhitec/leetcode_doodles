/**
    @author [mst]
    @brief  leetcode problems series
	206_reverse_linked_list
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    gains:

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

// simple iterative pointer action to revrse linked list
//
// sub: 69t 85s
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        if (head) {
            ListNode* curr = head;
            ListNode* next;

            while (curr){
                next = curr->next;  // prep forward
                curr->next = prev;  // link back
                prev = curr;        // relocate new head
                curr = next;        // advance
            }
        }
        return prev;
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
    addTailList (l5,6);
    addTailList (l5,7);

    cout << "given list..." << endl;
    printList(l5);

    ListNode* res = sol.reverseList(l5);
    cout << "reversed..." << endl;
    printList(res);


	return 0;
}
