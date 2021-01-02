#include <unordered_map>

#include "treenode.h"
using std::unordered_map;

struct status {
    int selected;
    int notSelected;
};

class Solution {
   public:
    // 继续优化，不适用哈希表
    int rob(TreeNode* root) {
        status s = roobdfs(root);
        return std::max(s.selected, s.notSelected);
    }

   private:
    unordered_map<TreeNode*, int> rroob;
    unordered_map<TreeNode*, int> nroob;
    status roobdfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = roobdfs(root->left);
        auto right = roobdfs(root->right);

        int selected = root->val + left.notSelected + right.notSelected;
        int notselected = std::max(left.selected, left.notSelected) +
                          std::max(right.selected, right.notSelected);

        return {selected, notselected};
    }
};