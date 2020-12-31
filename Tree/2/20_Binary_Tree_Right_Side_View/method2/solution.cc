#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 其次就是使用广度优先搜索了，我们总是先遍历右子树，
    // 如果我们记录每个节点的层数，那么每一层我们第一个遍历的
    // 就是最右面的节点了
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

   private:
    void dfs(TreeNode* root, int dep, vector<int>& result) {
        if (!root) return;

        if (dep == result.size()) {
            result.push_back(root->val);
        }

        if (root->right) dfs(root->right, dep + 1, result);
        if (root->left) dfs(root->left, dep + 1, result);
    }
};