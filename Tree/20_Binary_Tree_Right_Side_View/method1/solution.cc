#include <queue>
#include <vector>

#include "treenode.h"

using std::queue;
using std::vector;

class Solution {
   public:
    // 最容易相当的方法就是二叉树的层序遍历了，也就是BFS
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>{};

        vector<int> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        nodeQueue.push(nullptr);

        while (!nodeQueue.empty()) {
            root = nodeQueue.front();
            nodeQueue.pop();
            if (!root) break;

            if (root->left) nodeQueue.push(root->left);
            if (root->right) nodeQueue.push(root->right);

            if (!nodeQueue.empty() && !nodeQueue.front()) {
                result.push_back(root->val);
                nodeQueue.pop();
                nodeQueue.push(nullptr);
            }
        }

        return result;
    }
};