#include "solution.cc"

Node *arr2List(int arr[], int len) {
    Node *head = new Node(arr[0]);
    Node *pos = head;
    for (size_t i = 1; i < len; i++) {
        pos->next = new Node(arr[i]);
        pos = pos->next;
    }

    return head;
}

void printList(Node *head) {
    std::cout << "List: [";
    while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << head->val << "]" << std::endl;
}

void test() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    Node *node = arr2List(arr, 6);
    printList(node);
    Node *copyList = Solution().copyRandomList(node);
    printList(copyList);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}

/*
执行结果：通过
执行用时 :
    8 ms, 在所有 C++ 提交中击败了96.13%的用户
内存消耗 :
    13.5 MB, 在所有 C++ 提交中击败了84.37%的用户
*/
