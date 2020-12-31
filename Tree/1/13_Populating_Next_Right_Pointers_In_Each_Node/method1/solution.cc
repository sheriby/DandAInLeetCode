#include "treenode.h"

class Solution {
   public:
    // 题目要求的是使用常量的额外空间，或者使用递归。
    // 最简单的方法当然是使用递归啦
    Node* connect(Node* root) {
        if (!root || !root->left && !root->right) return root;

        connect(root->left);
        connect(root->right);

        Node *left = root->left, *right = root->right;
        while (left && right) {
            left->next = right;

            left = left->right;
            right = right->left;
        }

        return root;
    }
};