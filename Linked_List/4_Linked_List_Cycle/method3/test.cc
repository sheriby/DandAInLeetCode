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

ListNode *arr2CycleList(int arr[], int len) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *pos = head;

    for (size_t i = 1; i < len; i++) {
        pos->next = new ListNode(arr[i]);
        pos = pos->next;
    }

    pos->next = head;
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

ListNode *appendList(ListNode *list1, ListNode *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    ListNode *pos = list1;
    while (pos->next) { // find tail list node
        pos = pos->next;
    }

    pos->next = list2;
    return list1;
}

ListNode *cycleList(int head[], int len1, int cycle[], int len2) {
    ListNode *h = arr2List(head, len1);
    ListNode *c = arr2CycleList(cycle, len2);

    h = appendList(h, c);
    return h;
}

void testResult(ListNode *list, bool flag) {
    Solution solution;
    bool res = solution.hasCycle(list);
    std::cout << (res ? "Has Cycle" : "No Cycle") << std::endl;
    if (res == flag) {
        std::cout << "Test Success!" << std::endl;
    } else {
        std::cout << "Test Failure!" << std::endl;
    }
}

void test() {
    int head[] = {1, 2, 3};
    int cycle[] = {4, 5, 6};
    ListNode *list = cycleList(head, 3, cycle, 3);

    testResult(list, true);
}

void test2() {
    int cycle[] = {1, 2, 3, 4};
    ListNode *list = arr2CycleList(cycle, 4);

    testResult(list, true);
}

void test3() {
    int head[] = {1, 2, 3, 4};
    ListNode *list = arr2List(head, 4);

    testResult(list, false);
}

int main(int argc, char const *argv[]) {
    test();
    test2();
    test3();
    return 0;
}

/*
Test in leetcode
执行结果：通过
执行用时 :
    12 ms, 在所有 C++ 提交中击败了83.95%的用户
内存消耗 :
    9.9 MB, 在所有 C++ 提交中击败了20.22%的用户
*/
