#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#include "treenode.h"
using std::queue;
using std::stack;
using std::string;
using std::vector;

class Codec {
   public:
    // 还有一种方法比较容易想到，那就是二叉树的前序遍历和中序遍历可以决定其形状
    // 当然使用前序和后序也是可以的
    // 可以保存为 前序中序 的格式，前一半是前序，后一半是中序
    // 当然树中不能有重复的元素！！！
    string serialize(TreeNode* root) {
        string pre = "";
        preorder(root, pre);
        string in = "";
        inorder(root, in);

        return pre + "|" + in;
    }

    TreeNode* deserialize(string data) {
        if (data == "|") return nullptr;
        vector<int> pre = split(data.substr(0, data.size() / 2));
        vector<int> in = split(data.substr(data.size() / 2 + 1));
        return buildTree(pre, in);
    }

   private:
    void preorder(TreeNode* root, string& res) {
        if (!root) return;
        res += std::to_string(root->val) + ",";
        preorder(root->left, res);
        preorder(root->right, res);
    }

    void inorder(TreeNode* root, string& res) {
        if (!root) return;
        inorder(root->left, res);
        res += std::to_string(root->val) + ",";
        inorder(root->right, res);
    }

    vector<int> split(string data) {
        vector<int> result;
        int prev = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                string strval = data.substr(prev, i - prev);
                result.push_back(std::stoi(strval));
                prev = i + 1;
            }
        }

        return result;
    }

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
