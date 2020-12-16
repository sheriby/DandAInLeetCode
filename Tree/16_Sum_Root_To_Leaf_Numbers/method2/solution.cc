#include <iostream>
#include <queue>

#include "treenode.h"

using std::queue;

class Solution {
   public:
    // DFS是更加不错的
    // 此方法并没有修改原来的树
    int sumNumbers(TreeNode* root) { return dfs(root, 0); }

   private:
    int dfs(TreeNode* root, int prev) {
        if (!root) return 0;
        int cur = prev * 10 + root->val;
        if (!root->left && !root->right) {
            return cur;
        }
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};