/**
    @author [mst]
    @file   83_remove_list_duplicates.cpp
    @brief  title or quick description
    Given the head of a sorted linked list, delete all duplicates such that
    each element appears only once. Return the linked list sorted as well.
    Constraints:
    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.

    Gains:
    -cpp lists manipulation

    features, changelog:
    -2021.05.05:    -initial draft
                    -iterative solution better than: 95.28% time, 36.80% space
                    -removed the temp node and the delete and got: 98.72% time, 80.02% space

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

// HELPER METHODS
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


// initial iterative solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // [bp] maintain original head pointer, use a traversal help pointer
        ListNode* p = head;

        while (p != nullptr) {
            while ((p->next != nullptr) && (p->val == p->next->val)) {
                // [bp] here, using and deleting a temporary pointer
                // is bp, but gave a lower space score
                //ListNode* c = p->next;                
                //p->next = c->next;
                //delete(c);
                p->next = p->next->next;
            }
            p=p->next;
        }
        return head;
    }
};


////////////////// DRIVER
int main()
{
    using namespace std;    
	cout << "[mst] 83_remove_list_duplicates doodle" << '\n' << '\n';

    Solution sol1;

    // Input: head = [1,1,2,3,3]
    // Output: [1,2,3]
    ListNode* l1 = new ListNode(1);
    addTailList(l1, 1);
    addTailList(l1, 2);
    addTailList(l1, 3);
    addTailList(l1, 3);
    printList(l1);

    cout << "removing duplicates..." << endl;
    sol1.deleteDuplicates(l1);
    printList(l1);

	return 0;
}
