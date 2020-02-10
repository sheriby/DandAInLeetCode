#include "solution.cc"
#include <utility>

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

std::pair<ListNode*, ListNode*> cycleList(int head[], int len1, int cycle[], int len2) {
    ListNode *h = arr2List(head, len1);
    ListNode *c = arr2CycleList(cycle, len2);

    h = appendList(h, c);
    return std::make_pair(h, c);
}

void testResult(ListNode *list, ListNode* pos) {
    Solution solution;
    ListNode* res = solution.detectCycle(list);
    std::cout << (res ? "Has Cycle" : "No Cycle") << std::endl;
    if (res == pos) {
        std::cout << "Test Success!" << std::endl;
    } else {
        std::cout << "Test Failure!" << std::endl;
    }
}

void test() {
    int head[] = {1, 2, 3};
    int cycle[] = {4, 5, 6};
    auto res = cycleList(head, 3, cycle, 3);

    testResult(res.first, res.second);
}

void test2() {
    int cycle[] = {1, 2, 3, 4};
    ListNode *list = arr2CycleList(cycle, 4);

    testResult(list, list);
}

void test3() {
    int head[] = {1, 2, 3, 4};
    ListNode *list = arr2List(head, 4);

    testResult(list, nullptr);
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
    24 ms, 在所有 C++ 提交中击败了22.97%的用户
内存消耗 :
    12.2 MB, 在所有 C++ 提交中击败了5.15%的用户
*/
