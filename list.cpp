/**
    @author [mst]
    @file   list.cpp
    @brief  Linked list implementations

    [bp] there are different approaches to linked list implementations. A "value
    and pointer" node with a push function will suffice for quick tasks. A
    higher level "list" structure may be added to encapsulate additional
    functionality, tail pointers, prints, reverse methods.

    [wip] add reversall, deletion etc. functionality

    features, changelog:
    -2021.04: -initial draft

    @author [mst]
    @version 0.1 2022.04
*/


#include "list.h"
#include <iostream>         // usage of console prints


void ListNode::printList() {
    ListNode* lp = this;
    while (lp) {
        std::cout << lp->val << ',';
        lp = lp->next;
    }

    std::cout << "nullptr" << '\n';
}

// [demo] externally define a class method
ListNode::ListNode(int x, ListNode *next): val(x), next(next) {}


////////////////// DECL_IMPL


