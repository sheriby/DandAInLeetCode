#include <queue>

#include "treenode.h"

using std::queue;

class Solution {
   public:
    // 最简单的方法，使用二叉树的层序遍历
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            // 每一层的第一个节点的值
            res = nodeQueue.front()->val;

            int len = nodeQueue.size();
            for (int i = 0; i < len; i++) {
                root = nodeQueue.front();
                nodeQueue.pop();
                if (root->left) nodeQueue.push(root->left);
                if (root->right) nodeQueue.push(root->right);
            }
        }

        return res;
    }
};