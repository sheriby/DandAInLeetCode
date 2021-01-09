#include <vector>

#include "treenode.h"
using std::vector;

class Solution {
   public:
    // 可以在遍历的过程中找众数
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return results;
    }

   private:
    vector<int> results;
    int base, count, max_count;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        update(root->val);
        inorder(root->right);
    }

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