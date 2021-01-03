#include "treenode.h"

class Solution {
   public:
    // 双递归的简洁实现
    // 和法一本质上是一致的
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int path = countPath(root, sum);
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);

        return path + left + right;
    }

   private:
    int countPath(TreeNode* root, int sum) {
        if (!root) return 0;
        return (root->val == sum) + countPath(root->left, sum - root->val) +
               countPath(root->right, sum - root->val);
    }
};