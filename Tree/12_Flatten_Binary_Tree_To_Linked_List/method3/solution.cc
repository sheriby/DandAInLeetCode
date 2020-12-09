#include "treenode.h"

class Solution {
   public:
    // 比较巧妙的方法，不需要额外空间
    // 时间复杂度: O(N)
    // 空间复杂度: O(1)
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode *left, *predecessor;
        while (root) {
            left = root->left;
            if (left) {
                predecessor = left;
                while (predecessor->right) {
                    predecessor = predecessor->right;
                }
                predecessor->right = root->right;
                root->left = nullptr;
                root->right = left;
            }
            root = root->right;
        }
    }
};