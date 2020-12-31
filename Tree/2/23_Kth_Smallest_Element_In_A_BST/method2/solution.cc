#include <stack>
#include <vector>

#include "treenode.h"

using std::stack;
using std::vector;

class Solution {
   public:
    // 使用自己手动维护一个栈的方式进行中序遍历
    // 这样的好处是我们不必遍历完整棵树
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodeStack;
        while (true) {
            while (root) {
                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top();
            nodeStack.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};