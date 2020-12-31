#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 最简单的方法就是递归, 不过缺点就在于并没有将完全二叉树这个条件用上去
    // 所以说复杂度会稍微有点高
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};