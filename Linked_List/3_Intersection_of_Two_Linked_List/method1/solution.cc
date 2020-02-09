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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // use a set to store the pointer of node
        // traverse two list one by one and put the node pointer into the set
        // if finding same pointer in the set firstly, that is the result
        // pointer.
        std::set<ListNode *> s;
        while (headA && headB) {
            if (s.find(headA) != s.end()) { // find same pointer in the set
                return headA;
            } else {
                s.insert(headA);
            }

            if (s.find(headB) != s.end()) {
                return headB;
            } else {
                s.insert(headB);
            }

            headA = headA->next;
            headB = headB->next;
        }

        while (headA) {
            if (s.find(headA) != s.end()) {
                return headA;
            } else {
                headA = headA->next;
            }
        }

        while (headB) {
            if (s.find(headB) != s.end()) {
                return headB;
            } else {
                headB = headB->next;
            }
        }

        return nullptr;
    }
};