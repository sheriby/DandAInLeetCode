#include "treenode.h"

class Solution {
   public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_diff;
    }

   private:
    int min_diff = __INT_MAX__;
    int prev = -1;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev != -1 && root->val - prev < min_diff) {
            min_diff = root->val - prev;
        }
        prev = root->val;
        inorder(root->right);
    }
};