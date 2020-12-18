#include <iostream>
#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 当然我们也可以手动的维护一个栈
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int>{};

        vector<int> result;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        TreeNode* node = nullptr;

        while (!nodeStack.empty()) {
            node = nodeStack.top();
            nodeStack.pop();

            result.push_back(node->val);

            if (node->right) nodeStack.push(node->right);
            if (node->left) nodeStack.push(node->left);
        }

        return result;
    }
};