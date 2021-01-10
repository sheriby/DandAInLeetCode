#include "treenode.h"

class Solution {
   public:
    // Mirror反向中序遍历
    // 思路基本上是一样的
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;

        TreeNode* node = root;

        int sum = 0;
        while (node) {
            if (!node->right) {
                node->val += sum;
                sum = node->val;
                node = node->left;
                continue;
            }

            TreeNode* prev = node->right;
            while (prev->left && prev->left != node) prev = prev->left;

            if (!prev->left) {
                prev->left = node;
                node = node->right;
            } else {
                prev->left = nullptr;
                node->val += sum;
                sum = node->val;
                node = node->left;
            }
        }

        return root;
    }
};