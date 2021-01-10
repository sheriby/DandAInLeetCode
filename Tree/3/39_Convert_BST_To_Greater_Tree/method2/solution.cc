#include "treenode.h"

class Solution {
   public:
    // 不使用全局变量, 这递归说实话有点难理解的
    TreeNode* convertBST(TreeNode* root) {
        convertBSTDFS(root, 0);
        return root;
    }

   private:
    int convertBSTDFS(TreeNode* root, int parentValue) {
        if (!root) return parentValue;
        root->val += convertBSTDFS(root->right, parentValue);
        return convertBSTDFS(root->left, root->val);
    }
};