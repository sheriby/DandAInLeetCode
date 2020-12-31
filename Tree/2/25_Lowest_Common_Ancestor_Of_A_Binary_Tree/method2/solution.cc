#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 和二叉搜索数法二中类似的思路但是使用dfs实现
    // 该方法同样也有一定的局限性，必须保证给定的两个节点都是树中的
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        if (!left && !right) return nullptr;
        return left != nullptr ? left : right;
    }
};