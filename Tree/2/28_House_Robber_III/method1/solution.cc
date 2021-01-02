#include <unordered_map>

#include "treenode.h"
using std::unordered_map;

class Solution {
   public:
    // 这实质上就是一个动态规划的题目
    // 下面是一个基于备忘录的实现
    int rob(TreeNode* root) {
        return std::max(rootroob(root), norootroob(root));
    }

   private:
    unordered_map<TreeNode*, int> rroob;
    unordered_map<TreeNode*, int> nroob;
    int rootroob(TreeNode* root) {
        if (rroob.count(root)) return rroob[root];
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        int res = root->val + norootroob(root->left) + norootroob(root->right);
        rroob[root] = res;
        return res;
    }

    int norootroob(TreeNode* root) {
        if (nroob.count(root)) return nroob[root];
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int res = std::max(norootroob(root->left), rootroob(root->left)) +
                  std::max(norootroob(root->right), rootroob(root->right));
        nroob[root] = res;
        return res;
    }
};