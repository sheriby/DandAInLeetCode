#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 利用到完全二叉树的条件, 不过感觉还不如不用呢
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1;
        if (!root->right) return 2;

        int level = 1;
        int result = 0;
        TreeNode* node = root;
        while (node->right) {
            node = node->right;
            level++;
        }

        if (isFull(root->left, level - 1)) {
            result += (1 << level) + countNodes(root->right);
            return result;
        } else {
            result += (1 << (level - 1)) + countNodes(root->left);
            return result;
        }
    }

   private:
    bool isFull(TreeNode* root, int level) {
        while (root->right) {
            root = root->right;
            level--;
        }
        return level == 0;
    }
};