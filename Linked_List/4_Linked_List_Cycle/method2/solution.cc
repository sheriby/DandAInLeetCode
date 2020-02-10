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
        // another method is using fast and slow pointer
        // fast pointer move 2 node each time,
        // and slow pointer move 1 step each time.
        // if fast pointer and slow pointer meet, return true
        // if fast pointer meets nullptr, return false.

        ListNode *fast = head, *slow = head;

        while (fast && fast->next && slow) {
            fast = fast->next->next; // move two steps
            slow = slow->next; // move one step
            if (fast == slow) { // two pointers meet
                return true;
            }
        }
        return false;
    }
};