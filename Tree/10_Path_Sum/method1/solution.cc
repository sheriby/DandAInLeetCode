#include "treenode.h"

class Solution {
   public:
    // 首先就是最容易想到的递归算法,简单题做起来就是舒服
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;

        int val = sum - root->val;
        if (!root->left && root->right) return hasPathSum(root->right, val);
        if (!root->right && root->left) return hasPathSum(root->left, val);
        if (!root->left && !root->right) return root->val == sum;

        return hasPathSum(root->left, val) || hasPathSum(root->right, val);
    }
};