#include <iostream>
#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 最简单的方式就是使用递归的dfs了
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

   private:
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};