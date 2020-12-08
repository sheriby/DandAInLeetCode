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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!postorder.size() || postorder.size() != inorder.size())
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        int inorderIndex = inorder.size() - 1;

        for (int i = postorder.size() - 2; i >= 0; i--) {
            int postorderValue = postorder[i];
            TreeNode* node = nodeStack.top();

            if (node->val != inorder[inorderIndex]) {
                TreeNode* right = new TreeNode(postorderValue);
                node->right = right;
                nodeStack.push(right);
            } else {
                while (!nodeStack.empty() &&
                       nodeStack.top()->val == inorder[inorderIndex]) {
                    node = nodeStack.top();
                    nodeStack.pop();
                    inorderIndex--;
                }
                TreeNode* left = new TreeNode(postorderValue);
                node->left = left;
                nodeStack.push(left);
            }
        }

        return root;
    }
};