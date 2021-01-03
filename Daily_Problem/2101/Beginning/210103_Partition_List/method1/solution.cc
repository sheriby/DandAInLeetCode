#include "listnode.h"

class Solution {
   public:
    // 没有引入头结点，做起来需要验证很多非常复杂
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *less = nullptr, *great = nullptr;
        ListNode *lesshead = nullptr, *greathead = nullptr;
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            if (head->val < x) {
                if (!less) {
                    lesshead = head;
                    less = head;
                } else {
                    less->next = head;
                    less = less->next;
                }
            } else {
                if (!great) {
                    greathead = head;
                    great = head;
                } else {
                    great->next = head;
                    great = great->next;
                }
            }
            head->next = nullptr;
            head = next;
        }
        if (lesshead) {
            less->next = greathead;
            return lesshead;
        } else
            return greathead;
    }
};