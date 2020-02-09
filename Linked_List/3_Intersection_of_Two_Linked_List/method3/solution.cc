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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // lenA + all + lenB = lenB + all + lenA
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *posA = headA;
        ListNode *posB = headB;

        bool flagA = true;
        bool flagB = true;

        while (posA != posB) {
            if (posA->next == nullptr) {
                if (flagA) {
                    posA = headB;
                    flagA = false;
                } else {
                    return nullptr;
                }
            } else {
                posA = posA->next;
            }
            if (posB->next == nullptr) {
                if (flagB) {
                    posB = headA;
                    flagB = false;
                } else {
                    return nullptr;
                }
            } else {
                posB = posB->next;
            }
        }
        return posA;
    }
};