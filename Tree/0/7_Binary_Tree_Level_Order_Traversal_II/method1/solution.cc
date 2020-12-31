#include <queue>
#include <stack>
#include <vector>

#include "treenode.h"

using std::queue;
using std::stack;
using std::vector;

class Solution {
   public:
    // 最简单的方就是使用一个可以在两端插入的数组，但是C++中没有所以可以靠栈来实现逆序
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>>{};
        vector<vector<int>> result;
        stack<vector<int>> stk;
        queue<TreeNode*> nodeQueue;
        TreeNode* node = nullptr;
        nodeQueue.push(root);
        nodeQueue.push(nullptr);

        while (!nodeQueue.empty()) {
            vector<int> level;
            node = nodeQueue.front();
            nodeQueue.pop();
            while (node && !nodeQueue.empty()) {
                level.push_back(node->val);
                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);

                node = nodeQueue.front();
                nodeQueue.pop();
            }
            if (!nodeQueue.empty()) nodeQueue.push(nullptr);
            stk.emplace(level);
        }

        while (!stk.empty()) {
            result.emplace_back(stk.top());
            stk.pop();
        }

        return result;
    }
};