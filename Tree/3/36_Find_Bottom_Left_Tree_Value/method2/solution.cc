#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 同样可以使用基于dfs的层序遍历
    // 这样似乎更加简洁一点儿 而且效率更高
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return value;
    }

   private:
    int max_level = -1;
    int value = 0;
    void dfs(TreeNode* root, int level) {
        if (!root) return;
        if (level > max_level) {
            value = root->val;
            max_level = level;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};