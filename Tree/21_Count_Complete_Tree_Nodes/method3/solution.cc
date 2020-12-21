#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 二分法加位运算
    // 说实话花里胡哨的感觉没啥用
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int level = 0;
        TreeNode* node = root;
        while (node->left) {
            node = node->left;
            level++;
        }

        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

   private:
    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);
        while (root && bits > 0) {
            if (bits & k) {
                root = root->right;
            } else {
                root = root->left;
            }
            bits >>= 1;
        }
        return root != nullptr;
    }
};