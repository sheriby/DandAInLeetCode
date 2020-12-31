#include "treenode.h"

class Solution {
   public:
    // 题目要求的是使用常量的额外空间，或者使用递归。
    // 最简单的方法当然是使用递归啦
    Node* connect(Node* root) {
        if (!root || !root->left && !root->right) return root;

        connect(root->left);
        connect(root->right);

        // 这里我们如果使用递归的话，需要知道每一层左子树最右的节点，以及右子树最左的节点。
        // 说实话，代价可能很大，比如需要队列之类的数据结构
        // 但是如果真的要用到额外的队列这些数据结构的话，完全没有必要使用递归
        // 直接BFS层序遍历就完事了
        // 所以本题一定程度上不适合使用递归来做
    }
};