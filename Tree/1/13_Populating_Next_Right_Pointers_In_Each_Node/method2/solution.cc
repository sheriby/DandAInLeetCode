#include "treenode.h"

class Solution {
   public:
    // 不使用递归，利用上面一层的next建立新层
    Node* connect(Node* root) {
        if (!root || !root->left && !root->right) return root;
        Node *levelFirst = nullptr, *node = root;
        while (node && node->left) {
            levelFirst = node;
            while (node) {
                node->left->next = node->right;
                if (node->next) {
                    node->right->next = node->next->left;
                }
                node = node->next;
            }
            node = levelFirst->left;
        }
        return root;
    }
};