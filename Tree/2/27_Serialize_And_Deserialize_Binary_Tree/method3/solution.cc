#include <algorithm>
#include <queue>
#include <string>
#include <vector>

#include "treenode.h"
using std::queue;
using std::string;
using std::vector;

class Codec {
   public:
    // 使用如下的方式表示一棵树 (左子树递归)当前节点(右子树递归)
    // 使用X表示空
    string serialize(TreeNode* root) {
        if (!root) return "X";
        string left = "(" + serialize(root->left) + ")";
        string right = "(" + serialize(root->right) + ")";

        return left + std::to_string(root->val) + right;
    }

    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }

   private:
    inline TreeNode* parseSubTree(const string& data, int& index) {
        index++;
        auto subTree = parse(data, index);
        index++;
        return subTree;
    }

    inline int parseInt(const string& data, int& index) {
        int x = 0, sgn = 1;
        if (data[index] == '-') {
            sgn = -1;
            index++;
        }

        while (data[index] != '(') {
            x = x * 10 + data[index++] - '0';
        }

        return sgn * x;
    }

    TreeNode* parse(const string& data, int& index) {
        if (data[index] == 'X') {
            index++;
            return nullptr;
        }

        TreeNode* current = new TreeNode();
        current->left = parseSubTree(data, index);
        current->val = parseInt(data, index);
        current->right = parseSubTree(data, index);

        return current;
    }
};
