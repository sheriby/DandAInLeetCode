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
    ListNode *detectCycle(ListNode *head) {
        // use fast and slow pointer
        ListNode *fast = head, *slow = head;

        while (fast && fast->next && slow) {
            fast = fast->next->next; // move two steps
            slow = slow->next;       // move one step
            if (fast == slow) {      // two pointers meet
                fast = head;
                // move fast pointer to head
                // at this pointer, fast pointer moves one step each
                // and then they will meet at the cycle node.
                // 2(a + b) = a + b + c + b => a = b
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};