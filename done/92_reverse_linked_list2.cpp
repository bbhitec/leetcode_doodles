/**
    @author [mst]
    @brief  leetcode problems series
	92_reverse_linked_list2
    Given the head of a singly linked list and two integers
    left and right where left <= right, reverse the nodes
    of the list from position left to position right, and
    return the reversed list.

    gains:
    -medium-advanced linked list operations in cpp

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

// simple pointer action to revrse linked list
// there is also a by-value range-reverse
//
// sub: 31t 23s
class Solution {
public:

    ListNode* reverseBetweenValues(ListNode* head, int left, int right) {
        if (left == right) return head;
        if (head) {
            if (head->val > left) return head;

            ListNode* curr = head;
            ListNode* next;
            ListNode* last = nullptr;
            ListNode* start = nullptr;
            ListNode* prev = nullptr;

            // advance to left boundary
            while (curr->val < left) {
                last = curr;        // connection to the original list
                curr = curr->next;
            }
            start = curr;
            prev=last;

            while (curr->val <= right){
                next = curr->next;  // prep forward
                curr->next = prev;  // link back
                prev = curr;        // relocate new head
                curr = next;        // advance
            }

            // final reconnection
            start->next = curr;
            last->next = prev;
            return head;
        }
        return nullptr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* next;
        ListNode* last = head;
        ListNode* start = head;
        ListNode* prev = head;
        int rev_at_start = (left == 1);

        // advance to left boundary
        while (left-- > 1) {
            last = curr;        // connection to the original list
            curr = curr->next;
            right--;
        }
        start = curr;
        prev = last;

        while (right-- > 0){
            next = curr->next;  // prep forward
            curr->next = prev;  // link back
            prev = curr;        // relocate new head
            curr = next;        // advance
        }

        // final reconnection
        start->next = curr;
        if (rev_at_start) return prev;
        else last->next = prev;
        return head;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

    // case 1
    ListNode* l5 = nullptr;
    addTailList (l5,1);
    addTailList (l5,2);
    addTailList (l5,3);
    addTailList (l5,4);
    addTailList (l5,5);
    cout << "given list..." << endl;
    printList(l5);
    ListNode* res = sol.reverseBetween(l5,2,4);
    cout << "reversed..." << endl;
    printList(res);

    // // case 2
    // ListNode* l5 = nullptr;
    // addTailList (l5,5);
    // cout << "given list..." << endl;
    // printList(l5);
    // ListNode* res = sol.reverseBetween(l5,5,5);
    // cout << "reversed..." << endl;
    // printList(res);

    // // case 3
    // ListNode* l5 = nullptr;
    // addTailList (l5,3);
    // addTailList (l5,5);
    // cout << "given list..." << endl;
    // printList(l5);
    // ListNode* res = sol.reverseBetween(l5,1,2);
    // cout << "reversed..." << endl;
    // printList(res);


	return 0;
}
