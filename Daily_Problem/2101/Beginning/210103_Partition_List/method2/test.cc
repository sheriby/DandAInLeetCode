#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    ListNode* a = new ListNode(5);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(0);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    ListNode* result = s.partition(a, 3);
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}