#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 交换左子树和右子树的值
    // 很明显这是一个简单的递归题，先分别处理左右子树就完事了
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};