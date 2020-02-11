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

void test() {
    int arr[]{1, 4, 3, 2, 5, 2};
    int val = 3;

    ListNode *list = arr2List(arr, 6);
    printList(list);
    ListNode *res = Solution().partition(list, val);
    printList(res);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    8 ms, 在所有 C++ 提交中击败了73.02%的用户
内存消耗 :
    8.8 MB, 在所有 C++ 提交中击败了5.74%的用户
*/