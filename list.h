/**
    @author [mst]
    @file   list.h
    @brief  Linked list lib header

    features, changelog:
    -2021.04: -initial draft

    @author [mst]
    @version 0.1 2022.04
*/

#pragma once    // [demo][bp] avoid multiple includes. this is sometimes better
                // than using manual #ifndef LIST_H guards. we sometimes use
                // both methods to support older compilers
#ifndef _LIST_H
#define _LIST_H


// Definition for singly-linked list (node)
class ListNode {
public:
    int val;
    ListNode *next;

    // constructors
    ListNode() : val(0), next(nullptr) {}       // default empty constructor
    ListNode(int x) : val(x), next(nullptr) {}  // [demo] initializing constructor
    ListNode(int x, ListNode *next);

    // methods
    void printList();
};

// Optional wrapper list class
class LinkedList {
private:
    ListNode *head;
};


#endif // _LIST_H