#include "treenode.h"

class Solution {
   public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        sumOfLeftLeaves(root, res);
        return res;
    }

   private:
    void sumOfLeftLeaves(TreeNode* root, int& res) {
        if (!root) return;
        sumOfLeftLeaves(root->left, res);
        sumOfLeftLeaves(root->right, res);
        if (root->left && !root->left->left && !root->left->right)
            res += root->left->val;
    }
};