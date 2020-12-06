#include <iostream>
#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    // 隐示地进行二叉树的中序遍历，不必得到中序遍历的数组
    // 可以使用线索化二叉树的方法将空间复杂降低为O(1)
    // 时间复杂度: O(N)
    // 空间复杂度: O(1)
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode *x = nullptr, *y = nullptr, *prev = nullptr,
                 *predecessor = nullptr;
        while (root) {
            if (root->left) {
                predecessor = findPredecessor(root);
                if (predecessor->right) {
                    if (prev && prev->val > root->val) {
                        x = root;
                        if (!y) y = prev;
                    }
                    predecessor->right = nullptr;
                    prev = root;
                    root = root->right;
                } else {
                    predecessor->right = root;
                    root = root->left;
                }
            } else {
                if (prev && prev->val > root->val) {
                    x = root;
                    if (!y) y = prev;
                }
                prev = root;
                root = root->right;
            }
        }

        std::swap(x->val, y->val);
    }

    TreeNode* findPredecessor(TreeNode* root) {
        TreeNode* node = root->left;
        while (node->right && node->right != root) {
            node = node->right;
        }

        return node;
    }
};