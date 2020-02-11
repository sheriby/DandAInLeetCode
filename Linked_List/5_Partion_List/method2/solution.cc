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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less_head = new ListNode(0);
        ListNode *more_head = new ListNode(0);
        ListNode *less_pos = less_head;
        ListNode *more_pos = more_head;
        ListNode *pos = head;
        ListNode *next = nullptr;

        while (pos) {
            if (pos->val < x) {
                less_pos->next = pos;
                less_pos = pos;
            } else {
                more_pos->next = pos;
                more_pos = pos;
            }
            pos = pos->next;
        }

        less_pos->next = more_head->next;
        more_pos->next = nullptr; // very important!!
        return less_head->next;
    }
};
