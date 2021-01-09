#include <queue>
#include <vector>

#include "treenode.h"

using std::queue;
using std::vector;

class Solution {
   public:
    // 最简单的方法，使用二叉树的层序遍历
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int max_in_row = nodeQueue.front()->val;
            int len = nodeQueue.size();
            for (int i = 0; i < len; i++) {
                root = nodeQueue.front();
                nodeQueue.pop();
                if (root->val > max_in_row) {
                    max_in_row = root->val;
                }
                if (root->left) nodeQueue.push(root->left);
                if (root->right) nodeQueue.push(root->right);
            }
            result.push_back(max_in_row);
        }

        return result;
    }
};