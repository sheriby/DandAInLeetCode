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
        if (!head) {
            return nullptr;
        }
        // It is a little similiar to quick sort algorithm.
        // But the question is keeping the original order.
        ListNode *p = head;
        ListNode *q = nullptr;
        ListNode *temp = nullptr;

        while (p && p->val < x) {
            p = p->next;
        }
        if (!p) {
            return head;
        }
        q = p->next;

        while (q) {
            if (q->val < x) {
                // swapVal(p, p->next);
                swapVal(p, q);
                p = p->next;
                // change relative position here.
                temp = p;
                while (temp != q) {
                    swapVal(temp, q);
                    temp = temp->next;
                }
            }
            q = q->next;
        }

        return head;
    }

  private:
    void swapVal(ListNode *p, ListNode *q) {
        if (p == q) {
            return;
        }
        if (!p || !q) {
            return;
        }

        p->val ^= q->val ^= p->val ^= q->val;
    }
};

