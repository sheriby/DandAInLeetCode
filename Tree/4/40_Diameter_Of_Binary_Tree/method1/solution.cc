#include "treenode.h"

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max;
    }

   private:
    int max = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int value = left + right;
        max = value > max ? value : max;
        return 1 + (left > right ? left : right);
    }
};