/**
 * [here][wip] have all this shit cleaned up and sexy-sorted: new cpp template
 * leetcode solution and a general linked list doodle
 * 


 [mst] 2_add_two_numbers.cpp
 leetcode problems series
 2. Add Two Numbers
 You are given two non-empty linked lists representing two non-negative
 integers. The digits are stored in reverse order, and each of their nodes
 contains a single digit. Add the two numbers and return the sum as a linked
 list. You may assume the two numbers do not contain any leading zero, except
 the number 0 itself.
 https://leetcode.com/problems/add-two-numbers/



 [bp] linked lists
 there are different approaches to linked list implementations. Usually a node
 "value and pointer" node and a push function will suffice for quick tasks.
 A higher level "list" structure may be added to encapsulate additional
 functionality, tail pointers, print, reverse methods.

 features, changelog:
 -2022.01.27: -initial draft, accepted with 58.99% faster 91.74% less memory

    @author [mst]
    @version 0.1 2022.01.27
*/

////////////////// LIBS
#include <iostream>            // usage of console prints



////////////////// DECL_IMPL


//Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next);
    



};

// [demo] externally define a class method. Prototype must be defined!
ListNode::ListNode(int x, ListNode *next): val(x), next(next) {}

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
    //if (head == nulptr) { // [wip] unnecessary check?
    //    return
    //}
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

// note: given lists are non-empty, but we can entertain the case [wip]
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        int add = 0;
        int carry = 0;
        while (l1 && l2) {
            add = l1->val + l2->val + carry;
            addTailList(res,(add % 10));            
            carry = add / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        // treat different sized lists
        ListNode* lremainder;
        if (l1) {
            lremainder = l1;
        } else {
            lremainder = l2;
        }

        while (lremainder) {
            add = lremainder->val + carry;
            addTailList(res,(add % 10)); 
            carry = add / 10;

            lremainder = lremainder->next;
        }

        // dont forget the carry
        if (carry)
            addTailList(res, carry); 

        return res;
    }
};


////////////////// DRIVER
/*
	Returns the area of a circle with the given radius.
	@param radius The radius of the circle.
	@return The area of the circle.
*/ //[wip]
int main()
{
    // [bp] putting this in the global space is an overhead
    // even worse in a header file as would foce including in all users
    using namespace std;

    //[bp] using endl would force a flush.                            
	//cout << "[mst] doodle" << '\n' << '\n';

    cout << "[mst] 2_add_two_numbers doodle" << '\n' << '\n';
    Solution sol1;


    // Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    // Output: [8,9,9,9,0,0,0,1]

    ListNode* l5 = nullptr;
    addTailList (l5,9);
    addTailList (l5,9);
    addTailList (l5,9);
    addTailList (l5,9);
    addTailList (l5,9);
    addTailList (l5,9);
    addTailList (l5,9);
    ListNode* l6 = nullptr;
    addTailList (l6,9);
    addTailList (l6,9);
    addTailList (l6,9);
    addTailList (l6,9);  
    
    printList(l5);
    printList(l6);
    printList(sol1.addTwoNumbers(l5,l6));


    //////////////////////////////////////////    

    // Input: l1 = [0], l2 = [0]
    // Output: [0]

    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(0);
    printList(l3);
    printList(l4);
    printList(sol1.addTwoNumbers(l3,l4));

    //////////////////////////////////////////

    //Input: l1 = [2,4,3], l2 = [5,6,4]
    //Output: [7,0,8]
    //Explanation: 342 + 465 = 807

    // pre-build lists [wip] make builder function
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    //ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // ListNode* l2 = new ListNode(4);
    // pushList(l2,6);
    // pushList(l2,5);

    ListNode* l2 = new ListNode(5);
    addTailList (l2,6);
    addTailList (l2,4);

    //{2};
    //l1.next = new ListNode(4);
    //l1.next->next = new ListNode(3);    

    printList(l1);
    printList(l2);
    printList(sol1.addTwoNumbers(l1,l2));   





	//cin.get(); // pseudo-pause the console
	return 0;
}
