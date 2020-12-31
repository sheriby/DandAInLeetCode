#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 如果我们确定两个节点确实是本树中的话，可以利用BST的性质
    // 只需要一次遍历
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > p->val && root->val > q->val) {
                // 两个节点必在左子树
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                // 两个节点必在右子树
                root = root->right;
            } else
                // 一个在左一个在右，所以该节点就是最近的祖先节点
                return root;
        }
        return root;
    }
};