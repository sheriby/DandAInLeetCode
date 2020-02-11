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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // the second methods is two pointer.
        ListNode *p = l1, *q = l2;
        ListNode *head = new ListNode(0);
        ListNode *pos = head;
        while (p && q) {
            if (p->val < q->val) {
                pos->next = p;
                p = p->next;
            } else {
                pos->next = q;
                q = q->next;
            }
            pos = pos->next;
        }

        if (p) {
            pos->next = p;
        } else {
            pos->next = q;
        }

        return head->next;
    }
};