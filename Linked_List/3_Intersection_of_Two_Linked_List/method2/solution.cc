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
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        if (lenA > lenB) {
            headA = moveLen(headA, lenA - lenB);
        }
        if (lenA < lenB) {
            headB = moveLen(headB, lenB - lenA);
        }

        // headA and headB are in the same distance from the intersection
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }

  private:
    int getListLen(ListNode *list) {
        int cot = 0;
        while (list) {
            list = list->next;
            cot++;
        }
        return cot;
    }

    ListNode *moveLen(ListNode *list, unsigned int cot) {
        while (cot) {
            list = list->next;
            cot--;
        }
        return list;
    }
};