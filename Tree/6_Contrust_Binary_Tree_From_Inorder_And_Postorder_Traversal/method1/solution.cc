#include <unordered_map>
#include <vector>

#include "treenode.h"
using std::unordered_map;
using std::vector;

class Solution {
   public:
    // 使用了一种递归的构造方式。
    // 后序遍历的最后一个节点是根节点,
    // 中序遍历的某一个节点的左面是其左子树，右面是其右子树
    // 从而通过构造左子树和右子树递归构造出整棵树
    // 不过函数的参数并不是我们想要的，所以需要重载一下
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (size_t i = 0; i < inorder.size(); i++) {
            rootIndexMap[inorder[i]] = i;
        }

        return buildTree(inorder, 0, postorder, 0, inorder.size());
    }

   private:
    unordered_map<int, int> rootIndexMap;
    TreeNode* buildTree(vector<int>& inorder, int istart,
                        vector<int>& postorder, int pstart, int length) {
        if (length == 0) {
            return nullptr;
        }

        int rootVal = postorder[pstart + length - 1];
        if (length == 1) {
            return new TreeNode(rootVal);
        }

        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = rootIndexMap[rootVal];
        int leftLength = rootIndex - istart;
        int rightLength = length - leftLength - 1;
        root->left = buildTree(inorder, istart, postorder, pstart, leftLength);
        root->right = buildTree(inorder, rootIndex + 1, postorder,
                                pstart + leftLength, rightLength);

        return root;
    }
};