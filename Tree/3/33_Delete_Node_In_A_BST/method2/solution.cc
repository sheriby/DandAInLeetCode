#include "treenode.h"

class Solution {
   public:
    // 使用递归的方式
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right)
                root = nullptr;
            else if (root->left) {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            } else if (root->right) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

   private:
    // 前驱节点的值 assert root->left != nullptr
    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right) root = root->right;
        return root->val;
    }

    // 后继节点的值 assert root->right != nullptr
    int successor(TreeNode* root) {
        root = root->right;
        while (root->left) root = root->left;
        return root->val;
    }
};