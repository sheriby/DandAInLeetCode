#include <vector>

#include "treenode.h"

using std::vector;

class BSTIterator {
   public:
    // 提前中序遍历一下似乎就可以了
    // 但是并不满足题目的要求，虽然next和hasNext则两个函数都是O(1)的
    // 但是在迭代器的初始化占用了太多的资源
    BSTIterator(TreeNode* root) {
        index = 0;
        inorder(root);
    }

    int next() { return values[index++]; }

    bool hasNext() { return index != values.size(); }

   private:
    vector<int> values;
    int index;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
};