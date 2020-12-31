#include <algorithm>
#include <queue>
#include <vector>

#include "treenode.h"

using std::queue;
using std::vector;

class Solution {
   public:
    // 真正的最简单的方法是利用stl的函数实现逆序
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>>{};
        vector<vector<int>> result;
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
            result.emplace_back(level);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};