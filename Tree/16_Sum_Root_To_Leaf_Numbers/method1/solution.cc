#include <iostream>
#include <queue>

#include "treenode.h"

using std::queue;

class Solution {
   public:
    // 这题目很明显是一个二叉树遍历的题目，先来用用看BFS
    // 需要注意的是，此方法修改了原来的树
    // 如果不想修改的话，可以使用另外的队列来维护
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        queue<TreeNode*> nodeQueue;
        TreeNode* node = nullptr;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left) {
                node->left->val += node->val * 10;
                nodeQueue.push(node->left);
            }
            if (node->right) {
                node->right->val += node->val * 10;
                nodeQueue.push(node->right);
            }
            if (!node->left && !node->right) {
                result += node->val;
            }
        }

        return result;
    }
};