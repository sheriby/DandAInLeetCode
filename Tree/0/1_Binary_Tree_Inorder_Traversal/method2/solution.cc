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
    // 递归的方式内部维护了一个栈，如果想要使用迭代的方式解决这个问题，
    // 可以显示的维护这个栈。
    // 时间复杂度：O(N)
    // 空间复杂度: O(N)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;

        while (root || !nodeStack.empty()) {
            while (root) {
                nodeStack.push(root);
                root = root->left;
            }

            root = nodeStack.top();
            nodeStack.pop();
            result.push_back(root->val);
            // 这里root可能会变成空，如果为空的话，下一个循就从栈中取出一个节点
            root = root->right;
        }

        return result;
    }
};