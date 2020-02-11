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
    int a[]{1, 4, 7, 10, 13, 16};
    int b[]{2, 5, 8, 11, 14, 17};
    int c[]{3, 6, 9, 12, 15, 18};
    ListNode *l1 = arr2List(a, 6);
    ListNode *l2 = arr2List(b, 6);
    ListNode *l3 = arr2List(c, 6);
    ListNode *l4 = arr2List(c, 6);
    printList(l1);
    printList(l2);
    printList(l3);
    printList(l4);

    std::vector<ListNode *> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    lists.push_back(l4);

    ListNode *res = Solution().mergeKLists(lists);
    printList(res);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    24 ms, 在所有 C++ 提交中击败了89.76%的用户
内存消耗 :
    20.5 MB, 在所有 C++ 提交中击败了9.83%的用户
*/
