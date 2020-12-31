#include <iostream>
#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 当然我们也可以手动的维护一个栈
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return vector<int>{};

        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* node = root;
        TreeNode* prev = nullptr;

        while (!nodeStack.empty() || node) {
            while (node) {
                nodeStack.push(node);
                node = node->left;
            }

            node = nodeStack.top();
            nodeStack.pop();

            // node->right == prev 目的是放进进入死循环
            if (!node->right || node->right == prev) {
                result.emplace_back(node->val);
                prev = node;
                node = nullptr;
            } else {
                nodeStack.push(node);
                node = node->right;
            }
        }

        return result;
    }
};