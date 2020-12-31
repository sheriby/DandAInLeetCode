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
    // 这里采用维护一个栈进行迭代的方进行中序遍历
    // 时间复杂度: O(N)
    // 空间复杂度: O(H) H为树的高度
    void recoverTree(TreeNode *root) {
        stack<TreeNode *> nodeStack;
        TreeNode *x = nullptr, *y = nullptr, *prev = nullptr;

        while (root || !nodeStack.empty()) {
            while (root) {
                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top();
            nodeStack.pop();
            if (prev && prev->val > root->val) {
                x = root;
                if (!y) {
                    y = prev;
                } else {
                    break;
                }
            }
            prev = root;
            root = root->right;
        }
        std::swap(x->val, y->val);
    }
};