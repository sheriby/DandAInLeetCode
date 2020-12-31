#include <iostream>

#include "treenode.h"

class Solution {
   public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT32_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

   private:
    // 计算每一个节点的最大贡献度
    // 计算贡献度的同时计算最大路径和
    int maxGain(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        int leftGain = std::max(maxGain(root->left, maxSum), 0);
        int rightGain = std::max(maxGain(root->right, maxSum), 0);

        // 相当于以该节点为根的最大路径和
        int result = root->val + leftGain + rightGain;
        maxSum = std::max(result, maxSum);

        return root->val + std::max(leftGain, rightGain);
    }
};