#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 对于BST来说，很容易获取到路径
    // 两次遍历树，得到两个节点的路径数组
    // 从前向后比较，最后一个相同的就是他们的最近的公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp = getPath(root, p);
        vector<TreeNode*> pathq = getPath(root, q);
        int i = 0;
        while (i < pathp.size() && i < pathq.size() && pathp[i] == pathq[i]) {
            i++;
        }

        return pathp[i - 1];
    }

   private:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* node) {
        vector<TreeNode*> path;
        while (root != node) {
            path.push_back(root);
            if (root->val > node->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        path.push_back(node);
        return path;
    }
};