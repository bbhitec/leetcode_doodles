/**
    @author [mst]
    @brief  leetcode series
    2487_remove_nodes
    You are given the head of a linked list.
    Remove every node which has a node with a greater value anywhere to the right side of it.
    Return the head of the modified linked list.

    gains:
    -rd
    -run examples

    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <algorithm>    // usage of sort
#include <cstring>      // use of memset
#include <numeric>      // use of accumulate
using namespace std;


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
    ListNode *removeNodes(ListNode *head) {
        if (!head)
            return nullptr;

        head->next = removeNodes(head->next); // we going into the recursion while connecting the next head to be filtered
        if (head->next && head->val < head->next->val)  // keep the higher valued node, or the current one
            return head->next;
        else
            return head;
    }
};

////////////////// DRIVER
int main() {
    Solution s;

    ListNode* l1 = nullptr;
    addTailList (l1,5);
    addTailList (l1,2);
    addTailList (l1,13);
    addTailList (l1,3);
    addTailList (l1,8);

    cout << "the list:" << endl;
    printList(l1);

    ListNode* l2 = s.removeNodes(l1);

    cout << "result: " << endl;
    printList(l2);


    cout << "";
    return 0;
}