#include <iostream>
#include <set>

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
    bool hasCycle(ListNode *head) {
        // destroy original linked list
        while (head) {
            if (head->next == head) {
                return true;
            }
            if (head->next) {
                head->next = head->next->next;
                head = head->next;
            } else {
                return false;
            }
        }

        return false;
    }
};