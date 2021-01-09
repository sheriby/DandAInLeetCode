#include "treenode.h"

class Solution {
   public:
    // 使用Mirror中序遍历来优化空间复杂度
    int getMinimumDifference(TreeNode* root) {
        while (root) {
            if (!root->left) {
                update(root->val);
                root = root->right;
                continue;
            }

            TreeNode* prev = root->left;
            while (prev->right && prev->right != root) prev = prev->right;

            if (!prev->right) {
                prev->right = root;
                root = root->left;
            } else {
                update(root->val);
                prev->right = nullptr;
                root = root->right;
            }
        }
        return min_diff;
    }

   private:
    int min_diff = __INT_MAX__;
    int prev = -1;
    void update(int val) {
        if (prev != -1 && val - prev < min_diff) {
            min_diff = val - prev;
        }
        prev = val;
    }
};