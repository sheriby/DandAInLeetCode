#include <unordered_map>
#include <vector>

#include "treenode.h"
using std::unordered_map;
using std::vector;

class Solution {
   public:
    // 使用了一种递归的构造方式。
    // 前序遍历的第一个节点是根节点,
    // 中序遍历的某一个节点的左面是其左子树，右面是其右子树
    // 从而通过构造左子树和右子树递归构造出整棵树
    // 不过函数的参数并不是我们想要的，所以需要重载一下
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (size_t i = 0; i < inorder.size(); i++) {
            rootIndexMap[inorder[i]] = i;
        }

        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }

   private:
    unordered_map<int, int> rootIndexMap;
    TreeNode* buildTree(vector<int>& preorder, int pstart, vector<int>& inorder,
                        int istart, int length) {
        if (length == 0) {
            return nullptr;
        }
        if (length == 1) {
            return new TreeNode(preorder[pstart]);
        }

        TreeNode* root = new TreeNode(preorder[pstart]);
        // 这里多次在中序遍历中找根节点的位置，可以使用一个map以空间换时间
        // int rootIndex = istart;
        // while (inorder[rootIndex] != preorder[pstart]) {
        //     rootIndex++;
        // }
        int rootIndex = rootIndexMap[preorder[pstart]];
        int leftLength = rootIndex - istart;
        int rightLength = length - leftLength - 1;
        root->left =
            buildTree(preorder, pstart + 1, inorder, istart, leftLength);
        root->right = buildTree(preorder, pstart + leftLength + 1, inorder,
                                rootIndex + 1, rightLength);

        return root;
    }
};