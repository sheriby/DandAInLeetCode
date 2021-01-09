#include <vector>

#include "treenode.h"
using std::vector;

class Solution {
   public:
    // 使用Mirror遍历来优化中序遍历的空间复杂度
    vector<int> findMode(TreeNode* root) {
        // Mirror中序遍历
        while (root) {
            if (!root->left) {
                update(root->val);
                root = root->right;
                continue;
            }

            TreeNode* prev = root->left;
            while (prev->right && prev->right != root) prev = prev->right;

            if (!prev->right) {
                prev->right = root;
                root = root->left;
            } else {
                update(root->val);
                prev->right = nullptr;
                root = root->right;
            }
        }
        return results;
    }

   private:
    vector<int> results;
    int base, count, max_count;
    void update(int x) {
        if (x == base) {
            count++;
        } else {
            count = 1;
            base = x;
        }

        if (count == max_count) {
            results.push_back(x);
        } else if (count > max_count) {
            max_count = count;
            if (!results.empty()) results.clear();
            results.push_back(x);
        }
    }
};