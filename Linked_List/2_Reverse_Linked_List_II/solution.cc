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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pre = head;
        for (size_t i = 2; i < m; i++) {
            pre = pre->next;
        }
        // reverse m to n
        ListNode *pos;
        if (m == 1) {
            pos = head;
        } else {
            pos = pre->next;
        }
        ListNode *start = nullptr;
        ListNode *next;
        for (size_t i = m; i < n + 1; i++) {
            next = pos->next;
            pos->next = start;

            start = pos;
            pos = next;
        }

        if (m == 1) {
            head = start; // change head node when m = 1
        } else {
            pre->next = start;
        }

        ListNode *post = pos;
        while (start->next) {
            start = start->next;
        }
        start->next = post;

        return head;
    }
};