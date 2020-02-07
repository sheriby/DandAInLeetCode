#include <iostream>

/**
 * The definition from single-linked list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val)
        : val(val), next(nullptr) {} // here use nullptr instead of NULL
};

class Solution {
  public:
    // The Linked List is without head node.
    ListNode *reverseList(ListNode *head) {
        if (!head) { // no element
            return nullptr;
        }
        if (head && !head->next){ // only one element
            return head;
        }

        ListNode *list = reverseList(head->next); // return part after
        ListNode *pos = list;
        while (pos->next) { // found the list tail
            pos = pos->next;
        }
        pos->next = head;
        head->next = nullptr; // very important

        return list;
    }
};
