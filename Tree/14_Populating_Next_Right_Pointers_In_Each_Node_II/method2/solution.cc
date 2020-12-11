#include "treenode.h"

class Solution {
   public:
    // 不使用递归，利用上面一层的next建立新层
    Node* connect(Node* root) {
        if (!root || !root->left && !root->right) return root;
        Node *levelFirst = root, *node = root, *left, *next;
        while (levelFirst) {
            node = levelFirst;
            while (node) {
                if (!node->left && !node->right) {
                    node = node->next;
                    continue;
                }
                if (node->left && node->right) node->left->next = node->right;
                if (node->right)
                    left = node->right;
                else
                    left = node->left;

                next = node->next;

                while (next) {
                    if (!next->left && !next->right) {
                        next = next->next;
                        continue;
                    }

                    if (next->left) {
                        left->next = next->left;
                        break;
                    } else {
                        left->next = next->right;
                        break;
                    }
                }

                node = next;
            }
            while (levelFirst) {
                if (levelFirst->left) {
                    levelFirst = levelFirst->left;
                    break;
                }
                if (levelFirst->right) {
                    levelFirst = levelFirst->right;
                    break;
                }

                levelFirst = levelFirst->next;
            }
        }
        return root;
    }
};