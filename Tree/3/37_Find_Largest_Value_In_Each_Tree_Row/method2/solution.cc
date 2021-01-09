#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 同样可以使用基于dfs的层序遍历
    // 这样似乎更加简洁一点儿 而且效率更高
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return result;
    }

   private:
    vector<int> result;
    void dfs(TreeNode* root, int level) {
        if (!root) return;
        if (level == result.size())
            result.push_back(root->val);
        else if (root->val > result[level]) {
            result[level] = root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};