#include <iostream>
#include <vector>

#include "treenode.h"
using std::vector;

class Solution {
   public:
    // 还是和之前一样，非常显而易见的递归题目
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> results;
        vector<int> result;
        pathSum(root, sum, result, results);
        return results;
    }

   private:
    void pathSum(TreeNode* root, int sum, vector<int>& result,
                 vector<vector<int>>& results) {
        if (!root) return;
        if (!root->left && !root->right && root->val == sum) {
            result.push_back(root->val);
            results.push_back(result);
            result.pop_back();
            return;
        }

        result.push_back(root->val);
        int val = sum - root->val;

        if (root->left) {
            pathSum(root->left, val, result, results);
        }

        if (root->right) {
            pathSum(root->right, val, result, results);
        }

        result.pop_back();
    }
};
