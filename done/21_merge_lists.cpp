/**
    @author [mst]
    @file   21_merge_lists.cpp
    @brief  leetcode problems series

    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made
    by splicing together the nodes of the first two lists.

    Gains:
    -cpp lists operation, conditional control
    -recursion control

    features, changelog:
    -2021.04:	-initial draft: iterative solution. 75.34% time, 14.46% space
                -simple recursive solution, peeked. 6.41% time, 82.22% space

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints



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



class Solution {
public:
    // straightforward iterative solution
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;

        // use temporary pointers to preserve original lists
        ListNode* p;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        // consider empty lists
        if (!l1) return l2;
        if (!l2) return l1;

        // initial head pointer
        if(l1->val < l2->val) {
            res = p = l1;
            l1 = l1->next;
        } else {
            res = p = l2;
            l2 = l2->next;
        }

        // traverse remaining lists, link minimal nodes to result list
        while (l1 && l2) {
            if (l1 && (l1->val < l2->val)){
                p->next = l1;
                l1 = l1->next;
            } else if (l2) {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        // merge remaining loose ends
        while (l1){
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }

        while (l2){
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }

        return res;
    }
};

class SolutionRec {
public:
    // recursive solution
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // base cases
        if (!list1) return list2;
        if (!list2) return list1;

        // at each recursive call we isolate the smallest value
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};



////////////////// DRIVER
int main()
{
    using namespace std;
	cout << "[mst] 21. Merge Two Sorted Lists doodle" << '\n' << '\n';

    //Solution sol;
    SolutionRec sol;


    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    printList(l1);
    printList(l2);
    ListNode* l3 = sol.mergeTwoLists(l1,l2);
    printList(l3);


    cout << endl;
    l1 = nullptr;
    l2 = nullptr;
    printList(l1);
    printList(l2);
    l3 = sol.mergeTwoLists(l1,l2);
    printList(l3);


	return 0;
}
