#include <unordered_map>

#include "treenode.h"
using std::unordered_map;

class Solution {
   public:
    // 思路是一样的优化一下写法
    int rob(TreeNode* root) {
        roobdfs(root);
        return std::max(rroob[root], nroob[root]);
    }

   private:
    unordered_map<TreeNode*, int> rroob;
    unordered_map<TreeNode*, int> nroob;
    void roobdfs(TreeNode* root) {
        if (!root) return;
        roobdfs(root->left);
        roobdfs(root->right);

        rroob[root] = root->val + nroob[root->left] + nroob[root->right];
        nroob[root] = std::max(rroob[root->left], nroob[root->left]) +
                      std::max(rroob[root->right], nroob[root->right]);
    }
};