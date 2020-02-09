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

void printList(ListNode *head) {
    std::cout << "List: [";
    while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << head->val << "]" << std::endl;
}

ListNode* appendList(ListNode *list1, ListNode *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2){
        return list1;
    }
    ListNode* pos = list1;
    while (pos->next) { // find tail list node
        pos = pos->next;
    }

    pos->next = list2;
    return list1;
}

std::pair<ListNode *, ListNode *> 
intersectionList(int arr1[], int len1,int arr2[], int len2,
                int arr3[], int len3) {
    ListNode *list1 = arr2List(arr1, len1);
    ListNode *list2 = arr2List(arr2, len2);
    ListNode *list3 = arr2List(arr3, len3);

    list1 = appendList(list1, list3);
    list2 = appendList(list2, list3);

    return std::make_pair(list1, list2);
}

void test() {
    int arr1[] = {1, 6, 3, 4};
    int arr2[] = {2, 5};
    int arr3[] = {7, 8, 9};
    auto lists = intersectionList(arr1, 4, arr2, 2, arr3, 3);
    ListNode* list1 = lists.first;
    ListNode* list2 = lists.second;
    printList(list1);
    printList(list2);

    Solution solution;
    ListNode* res = solution.getIntersectionNode(list1, list2);
    std::cout << res->val << std::endl;
    if (arr3[0] == res->val){
        std::cout << "Test Success" << std::endl;
    }else{
        std::cout << "Test Failure" << std::endl;
    }
}

void test2() {
    int arr1[] = {1, 6, 3, 4, 1, 4, 5};
    int arr2[] = {2};
    int arr3[] = {9};
    auto lists = intersectionList(arr1, 7, arr2, 1, arr3, 1);
    ListNode* list1 = lists.first;
    ListNode* list2 = lists.second;
    printList(list1);
    printList(list2);

    Solution solution;
    ListNode* res = solution.getIntersectionNode(list1, list2);
    std::cout << res->val << std::endl;
    if (arr3[0] == res->val){
        std::cout << "Test Success" << std::endl;
    }else{
        std::cout << "Test Failure" << std::endl;
    }
}

void test3() {
    int arr1[] = {1, 6, 3, 4, 1, 4, 5};
    int arr2[] = {2, 5, 6, 7};

    ListNode* list1 = arr2List(arr1, 7);
    ListNode* list2 = arr2List(arr2, 4);
    printList(list1);
    printList(list2);

    Solution solution;
    ListNode* res = solution.getIntersectionNode(list1, list2);
    if (res == nullptr){
        std::cout << "Test Success" << std::endl;
    }else{
        std::cout << "Test Failure" << std::endl;
    }
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
    64 ms, 在所有 C++ 提交中击败了40.62%的用户
内存消耗 :
    17 MB, 在所有 C++ 提交中击败了18.33%的用户
*/