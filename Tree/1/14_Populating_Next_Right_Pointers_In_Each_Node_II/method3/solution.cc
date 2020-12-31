#include "treenode.h"

class Solution {
   public:
    // 添加dummy节点，一种更加简洁的实现方式
    // 不仅可以借助上一层的next，还可以借助左边已经建好的next
    Node* connect(Node* root) {
        if (!root || !root->left && !root->right) return root;
        Node* dummy = new Node;
        Node* pre = dummy;
        Node* currentNode = root;
        while (currentNode) {
            if (currentNode->left) {
                pre->next = currentNode->left;
                pre = pre->next;
            }

            if (currentNode->right) {
                pre->next = currentNode->right;
                pre = pre->next;
            }

            currentNode = currentNode->next;

            if (!currentNode) {
                currentNode = dummy->next;
                dummy->next = nullptr;
                pre = dummy;
            }
        }

        return root;
    }
};