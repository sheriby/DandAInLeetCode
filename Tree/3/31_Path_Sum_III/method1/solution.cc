#include "treenode.h"

class Solution {
   public:
    // 分两种情况来讨论，一种是包含根节点，一种不包含根节点
    // 这其实也是一种动态规划
    // 类似之前做的打家劫舍III
    int pathSum(TreeNode* root, int sum) {
        return pathSumRoot(root, sum) + pathSumNoRoot(root, sum);
    }

   private:
    int pathSumRoot(TreeNode* root, int sum) {
        if (!root) return 0;
        return (root->val == sum) + pathSumRoot(root->left, sum - root->val) +
               pathSumRoot(root->right, sum - root->val);
    }

    int pathSumNoRoot(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSumRoot(root->left, sum) + pathSumRoot(root->right, sum) +
               pathSumNoRoot(root->left, sum) + pathSumNoRoot(root->right, sum);
    }
};