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
        if (!head) {
            return nullptr;
        }
        ListNode *pos = head;
        ListNode *next = head->next;
        ListNode *nnext = next ? next->next : nullptr;
        pos->next = nullptr;
        while (next) {
            next->next = pos;

            pos = next;
            next = nnext;
            nnext = nnext ? nnext->next : nullptr;
        }

        return pos;
    }
};
