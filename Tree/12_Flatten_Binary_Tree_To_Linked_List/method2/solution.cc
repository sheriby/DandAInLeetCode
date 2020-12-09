#include <stack>

#include "treenode.h"

using std::stack;

class Solution {
   public:
    // 前序遍历和展开同时进行，因为会破坏树结构，因此不可以使用递归的方式
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* prev = nullptr;

        while (!nodeStack.empty()) {
            root = nodeStack.top();
            nodeStack.pop();

            if (prev) {
                prev->left = nullptr;
                prev->right = root;
            }
            prev = root;

            if (root->right) nodeStack.push(root->right);
            if (root->left) nodeStack.push(root->left);
        }
    }
};