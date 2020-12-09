#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 最显而易见的办法就是使用前序遍历, 因为使用前序遍历之后的节点是有序的
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> list;
        inorder(root, list);
        for (size_t i = 0; i + 1 < list.size(); i++) {
            list[i]->left = nullptr;
            list[i]->right = list[i + 1];
        }
    }

   private:
    void inorder(TreeNode* root, vector<TreeNode*>& list) {
        if (!root) return;
        list.push_back(root);
        if (root->left) inorder(root->left, list);
        if (root->right) inorder(root->right, list);
    }
};