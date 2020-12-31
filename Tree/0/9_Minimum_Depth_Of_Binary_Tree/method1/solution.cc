#include "treenode.h"

class Solution {
   public:
    // 依旧是最简单的递归
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};