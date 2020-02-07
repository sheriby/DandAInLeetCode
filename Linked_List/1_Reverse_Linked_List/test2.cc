#include "solution2.cc"
#include <iostream>

ListNode *arr2List(int arr[], int len) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *pos = head;
    for (size_t i = 1; i < len; i++) {
        pos->next = new ListNode(arr[i]);
        pos = pos->next;
    }

    return head;
}

void printList(ListNode *head) {
    std::cout << "List: [";
    while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << head->val << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *list = arr2List(arr, 10);
    printList(list);
    // List: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    Solution solution;
    list = solution.reverseList(list);
    printList(list);
    // List: [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    // Test OK!

    return 0;
}

/*
Test in LeetCode
执行结果：通过
执行用时 :
    28 ms, 在所有 C++ 提交中击败了7.73%的用户
内存消耗 :
    9.5 MB, 在所有 C++ 提交中击败了5.00%的用户
*/