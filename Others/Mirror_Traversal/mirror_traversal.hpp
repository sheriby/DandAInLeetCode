#include <vector>

#include "treenode.h"
using std::vector;

class MirrorTraversal {
   public:
    // 使用Mirror中序遍历将二叉树的中序遍历的空间复杂度降低到O(1)
    static vector<int> mirrorTraversal(TreeNode* root) {
        vector<int> list;
        while (root) {
            // 如果没有左子树，遍历当前节点，然后转到右子树
            if (!root->left) {
                list.push_back(root->val);
                root = root->right;
                continue;
            }

            // 有左子树，找左子树中的前驱节点
            TreeNode* pre = root->left;
            while (pre->right && pre->right != root) {
                pre = pre->right;
            }

            // 前驱节点的右子树为空，代表当前的树的左子树还没有开始遍历
            if (!pre->right) {
                // 添加后继标记，通过right可以到达自己的后继节点
                pre->right = root;
                root = root->left;
            } else {  // 不为空，代表当前数的左子树已经遍历完成
                // 删除之前添加的后继节点
                pre->right = nullptr;
                list.push_back(root->val);
                root = root->right;
            }
        }
        return list;
    }
};