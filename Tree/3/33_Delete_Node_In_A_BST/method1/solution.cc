#include "treenode.h"

class Solution {
   public:
    // 分类讨论，如果是叶子节点，如果不是
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* node = root;
        while (node && key != node->val) {
            parent = node;
            if (key < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        if (key != node->val) return root;

        if (!node->left) {
            if (!parent) return root->right;
            if (parent->left == node)
                parent->left = node->right;
            else
                parent->right = node->right;
            return root;
        }

        node->val = findAndDeletePrev(node);
        return root;
    }

   private:
    int findAndDeletePrev(TreeNode* node) {
        if (!node->left->right) {
            int ret = node->left->val;
            node->left = node->left->left;
            return ret;
        }

        TreeNode* parent = node;
        node = node->left;

        while (node->right) {
            parent = node;
            node = node->right;
        }
        int ret = node->val;
        parent->right = node->left;
        return ret;
    }
};