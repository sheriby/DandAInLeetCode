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
        // the simplest method is using a set to save node
        // when finding same node, return true
        std::set<ListNode *> s;
        while (head) {
            if (s.find(head) != s.end()) {
                return true;
            } else {
                s.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};