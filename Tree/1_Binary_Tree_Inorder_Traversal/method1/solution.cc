#include <iostream>
#include <vector>
#include "treenode.h"

using std::vector;

 static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> result;
    
    // 使用递归的方式进行二叉树的中序遍历，这也是简单的方式
    // 时间复杂度 O(N)
    // 空间复杂度 O(N)
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            result.push_back(root->val);
            inorderTraversal(root->right);
        }
        return result;
    }
};