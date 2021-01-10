#include "treenode.h"

class Solution {
   public:
    int prev = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        convertBST(root->right);
        root->val += prev;
        prev = root->val;
        convertBST(root->left);
        return root;
    }
};