#include <iostream>

#include "treenode.h"

class Solution {
   public:
    // 最简单的方法，递归的判断，左右子树都要是平衡的，该节点也要是平衡的
    // 时间复杂度: O(N^2)
    // 空间复杂度: O(N)
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) &&
               std::abs(depth(root->left) - depth(root->right)) <= 1;
    }

   private:
    // 求某一个节点的深度
    int depth(TreeNode* root) {
        if (!root) return 0;
        return std::max(depth(root->left), depth(root->right)) + 1;
    }
};