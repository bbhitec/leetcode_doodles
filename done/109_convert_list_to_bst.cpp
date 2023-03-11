/**
    @author [mst]
    @brief  leetcode series
    109_convert_list_to_bst
	Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced  binary search tree.

    gains:
    -bst, lists and balancing in cpp

    @version 0.1 2023.03
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
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

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(-1), left(nullptr), right(nullptr){}	// here invalid value is -1
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}

	void printInOrder(){
		if (left) { left->printInOrder(); }
		cout << val << endl;
		if (right) { right->printInOrder(); }
	}
/*
	// binary search tree insertion
	void insert(int x) {
		// empty tree case
		if (val == -1) {
			val = x;
			return;
		}

		if (x <= val) {	// value lesser than the root will be routed left
			if (left == nullptr){ left = new TreeNode(x); }	// empty left node
			else {
				left->insert(x);	// non empty left node
			}
		}
		else {	// value higherr than the root will be routed right
			if (right == nullptr){ right = new TreeNode(x); }	// empty right node
			else {
				right->insert(x);	// non empty right node
			}
		}
	}

	// insertion overloaded for array-to-tree conversion
	void insert(int arr[], int size) {
		if (size == 0) return;
		for(int i = 0; i<size; i++) {
			this->insert(arr[i]);
		}
	}
    */
};


// snipped recursive solution:
// insert (in-order) into a new bst, always take middle-of-list value to keep list balanced
//
// sub: 61t 43s
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);

        ListNode *mid = findMid(head);
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }

private:
    ListNode *findMid(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        return slow;
    }
};

// sniped solution2
// same idea, use counting to determine the middle value
//
// sub: 78t 71s
class Solution1 {
private:
    ListNode* curr;
    TreeNode* treeify(int i, int j) {
        if (j < i) return nullptr;
        int mid = (i + j) >> 1;
        TreeNode* node = new TreeNode();
        node->left = treeify(i, mid - 1);
        node->val = curr->val, curr = curr->next;
        node->right = treeify(mid + 1, j);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        curr = head;
        while (curr) curr = curr->next, count++;
        curr = head;
        return treeify(1, count);
    }
};



////////////////// DRIVER
int main()
{
    Solution s;

    ListNode* l = nullptr;
    addTailList (l,-10);
    addTailList (l,-3);
    addTailList (l,0);
    addTailList (l,5);
    addTailList (l,9);
    printList(l);

    TreeNode* res = s.sortedListToBST(l);

    res->printInOrder();


    return 0;
}