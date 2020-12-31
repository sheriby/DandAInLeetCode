#include <iostream>

#include "treenode.h"

class Solution {
   public:
    // 第一种方法是自顶向下的递归，一个节点的depth函数多次被调用，导致较高的时间复杂度
    // 可以采用自底向上的递归避免这一点
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    bool isBalanced(TreeNode* root) { return depth(root) >= 0; }

   private:
    int depth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        if (leftDepth == -1 || rightDepth == -1 ||
            std::abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        return std::max(leftDepth, rightDepth) + 1;
    }
};