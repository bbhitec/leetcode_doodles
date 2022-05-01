/**
    @author [mst]
    @file   <filename>.<extension>    
    @brief  title or quick description
    full/optional description: this is a placeholder
    template for new files creation

    features, changelog:
    -2021.04:	-initial draft
				[wip][here] indicate optional miscompletion

    @version 0.1 2022.04
*/


////////////////// LIBS
#include <iostream>            // usage of console prints

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
    //if (head == nulptr) { // [wip] unnecessary check?
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        ListNode* l1;
        ListNode* l2;

        // initial head
        if(l1->val < l2->val) {
            res = l1;
            l1 = l1->next;
        } else {
            res = l2;
            l2 = l2->next;
        }

        while (l1 || l2) {
            if (l1->val < l2->val)
        }

        return res;
    }
};


////////////////// DECL_IMPL



////////////////// DRIVER
int main()
{
    using namespace std;    
	cout << "[mst] doodle" << '\n' << '\n';

    Solution sol;

    ListNode* l1 = new ListNode(2, new ListNode(3, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(5)));

    printList(l1);
    printList(l2);
    ListNode* l3 = sol.mergeTwoLists(l1,l2);

    printList(l3);


	return 0;
}
