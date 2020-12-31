#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 还是寻找到根节点到这两个节点的路径
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        getPath(root, p, pathp);
        vector<TreeNode*> pathq;
        getPath(root, q, pathq);

        int i = pathp.size() - 1;
        int j = pathq.size() - 1;
        while (i >= 0 && j >= 0 && pathp[i] == pathq[j]) {
            i--;
            j--;
        }

        return pathp[i + 1];
    }

   private:
    // 这里不再是二叉搜索数的，修改算法即可
    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (!root) return false;

        if (root == node || getPath(root->left, node, path) ||
            getPath(root->right, node, path)) {
            path.push_back(root);
            return true;
        }

        return false;
    }
};