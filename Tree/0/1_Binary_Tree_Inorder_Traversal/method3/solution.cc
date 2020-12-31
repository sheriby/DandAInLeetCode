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
    // 将二叉树线索化，从而不适用额外的栈空进行中序遍历
    // 时间复杂度：O(N)
    // 空间复杂度: O(1) 不需要使用额外的空间
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        // 用来保存当前访问节点的中序前驱节点
        TreeNode* predecessor;
        while (root) {
            if (!root->left) {
                result.push_back(root->val);
                // 遍历右子树
                root = root->right;
            } else if (root->left) {
                // 如果有左子树的话，找到前驱节点，也就是左子树当中最后一个遍历节点
                predecessor = findPredecessor(root);
                if (predecessor->right) {
                    // 说明前驱节点已经遍历过了，也就是左子树全部遍历完了
                    result.push_back(root->val);
                    // 断开之前设置的标记
                    predecessor->right = nullptr;
                    // 遍历右子树
                    root = root->right;
                } else {
                    // 没有遍历过，添加标记
                    predecessor->right = root;
                    // 左子树还没有遍历,继续遍历左子树
                    root = root->left;
                }
            }
        }

        return result;
    }

    TreeNode* findPredecessor(TreeNode* root) {
        TreeNode* node = root;
        if (!node->left) return nullptr;
        node = node->left;
        // node->right != root 如果node->right == root，该node就是之前标记过了的前驱节点
        while (node->right && node->right != root) {
            node = node->right;
        }

        return node;
    }
};