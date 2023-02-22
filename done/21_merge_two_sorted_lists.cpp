/**
    @author [mst]
    @brief  leetcode problems series
	21_merge_two_sorted_lists
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should
    be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.

    gains:
    -basic cpp linked list operations

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


class Solution {
public:
    // this problem is based on merging just
    // two lists: used in leetcode 21
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return dummy->next;
    }

};


////////////////// DRIVER
int main()
{
	Solution sol;

    ListNode* l1 = nullptr;
    addTailList (l1,1);
    addTailList (l1,2);
    addTailList (l1,4);
    ListNode* l2 = nullptr;
    addTailList (l2,1);
    addTailList (l2,3);
    addTailList (l2,4);
    cout << "merging..." << endl;
    printList(l1);
    printList(l2);

    ListNode* res = sol.mergeTwoLists(l1,l2);
    cout << "res:" << endl;
    printList(res);

	return 0;
}
