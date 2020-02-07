#include "solution.cc"

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
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *list = arr2List(arr, 10);
    printList(list);
    Solution solution;
    // list = solution.reverseBetween(list, 2, 8);
    // list = solution.reverseBetween(list, 1, 6);
    list = solution.reverseBetween(list, 1, 10);
    printList(list);
    // Test OK!
    return 0;
}

/*
Test in leetcode
执行结果：通过
执行用时 :
    4 ms, 在所有 C++ 提交中击败了81.95%的用户
内存消耗 :
    8.8 MB, 在所有 C++ 提交中击败了5.17%的用户
*/