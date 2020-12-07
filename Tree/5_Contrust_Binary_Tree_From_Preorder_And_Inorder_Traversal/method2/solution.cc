#include <stack>
#include <vector>

#include "treenode.h"
using std::stack;
using std::vector;

class Solution {
   public:
    // 使用迭代实现，方法比较的巧妙，说实话理解起来比较困难一点
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || preorder.size() != inorder.size())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        int inorderIndex = 0;

        for (int i = 1; i < preorder.size(); i++) {
            int preorderValue = preorder[i];
            TreeNode* node = nodeStack.top();

            if (node->val != inorder[inorderIndex]) {
                TreeNode* left = new TreeNode(preorderValue);
                node->left = left;
                nodeStack.push(left);
            } else {
                while (!nodeStack.empty() &&
                       nodeStack.top()->val == inorder[inorderIndex]) {
                    node = nodeStack.top();
                    nodeStack.pop();
                    inorderIndex++;
                }
                TreeNode* right = new TreeNode(preorderValue);
                node->right = right;
                nodeStack.push(right);
            }
        }

        return root;
    }
};