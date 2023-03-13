/**
    @author [mst]
    @brief  leetcode problems series
	23_merge_k_sorted_lists
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    gains:
    -advanced linked list operation in cpp
    -merge sort algorithm

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

// 
// sub: 95t 31s
class Solution {
public:
    // this problem is based on merging just
    // two lists: used in leetcode 21
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        if (lists.empty() || sz==0) return nullptr;


        // a merg-sort approach: merge pairs
        // of lists until a single list is formed
        while (sz > 1) {
            vector<ListNode*> merged;
            ListNode* l1;
            ListNode* l2;

            for (int i=0; i<sz; i+=2) {
                l1 = lists[i];
                l2 = ((i+1) < sz)? lists[i+1] : nullptr;
                merged.push_back(mergeLists(l1,l2));
            }
            lists = merged;
            sz = lists.size();
        }
        return lists[0];
    }


};


////////////////// DRIVER
int main()
{
	Solution sol;

    ListNode* l1 = nullptr;
    addTailList (l1,1);
    addTailList (l1,4);
    addTailList (l1,5);
    ListNode* l2 = nullptr;
    addTailList (l2,1);
    addTailList (l2,3);
    addTailList (l2,4);
    ListNode* l3 = nullptr;
    addTailList (l3,2);
    addTailList (l3,6);

    cout << "merging..." << endl;
    printList(l1);
    printList(l2);
    printList(l3);

    vector<ListNode*> lists{l1,l2,l3};
    ListNode* res = sol.mergeKLists(lists);
    cout << "res:" << endl;
    printList(res);




	return 0;
}
