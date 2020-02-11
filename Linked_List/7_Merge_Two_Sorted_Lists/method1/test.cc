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

void test(){
    int arr1[]{1, 3, 5, 7, 9};
    int arr2[]{2, 4, 6, 8, 10};

    ListNode* l1 = arr2List(arr1, 5);
    ListNode* l2 = arr2List(arr2, 5);
    printList(l1);
    printList(l2);

    ListNode* res = Solution().mergeTwoLists(l1, l2);
    printList(res);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    12 ms, 在所有 C++ 提交中击败了47.54%的用户
内存消耗 :
    9 MB, 在所有 C++ 提交中击败了25.17%的用户
*/