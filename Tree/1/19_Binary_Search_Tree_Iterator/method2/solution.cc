#include <stack>

#include "treenode.h"

using std::stack;

class BSTIterator {
   public:
    // 使用迭代的方式，手动的维护这个栈
    BSTIterator(TreeNode* root) { pushLeft(root); }

    int next() {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();

        if (node->right) {
            pushLeft(node->right);
        }

        return node->val;
    }

    bool hasNext() { return !nodeStack.empty(); }

   private:
    stack<TreeNode*> nodeStack;

    void pushLeft(TreeNode* root) {
        while (root) {
            nodeStack.push(root);
            root = root->left;
        }
    }
};