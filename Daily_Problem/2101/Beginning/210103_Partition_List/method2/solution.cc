#include "listnode.h"

class Solution {
   public:
    // 引入头结点，简化逻辑
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesshead = new ListNode(0);
        ListNode* greathead = new ListNode(0);
        ListNode *less = lesshead, *great = greathead;
        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                great->next = head;
                great = great->next;
            }
            head = head->next;
        }
        less->next = greathead->next;
        great->next = nullptr;
        return lesshead->next;
    }
};