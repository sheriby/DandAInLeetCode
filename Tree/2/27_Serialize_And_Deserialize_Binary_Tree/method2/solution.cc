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
    // 法一就是我一开始实现的思路，都使用的队列来遍历树，我们同样可以选择使用递归
    // 但是这和leetcode官方使用的序列化方式就不一样了，法一是一样的
    // 该方法会发生TLE，无法通过leetcode中的所有测试用例
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        string result = serialize(root, "");
        result = "[" + result;
        result[result.size() - 1] = ']';

        return result;
    }

    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        vector<TreeNode*> nodes = str2TreeArray(data);
        std::reverse(nodes.begin(), nodes.end());
        return deserialize(nodes);
    }

   private:
    string serialize(TreeNode* root, string str) {
        if (!root) {
            str += "null,";
        } else {
            str += std::to_string(root->val) + ",";
            str = serialize(root->left, str);
            str = serialize(root->right, str);
        }
        return str;
    }
    TreeNode* deserialize(vector<TreeNode*>& nodes) {
        if (!nodes.back()) {
            nodes.pop_back();
            return nullptr;
        }

        TreeNode* root = nodes.back();
        nodes.pop_back();
        root->left = deserialize(nodes);
        root->right = deserialize(nodes);

        return root;
    }

    vector<TreeNode*> str2TreeArray(string data) {
        vector<TreeNode*> nodes;
        int prev = 1;
        for (int i = 2; i < data.size(); i++) {
            if (data[i] == ',' || data[i] == ']') {
                string tmp = data.substr(prev, i - prev);
                if (tmp == "null")
                    nodes.push_back(nullptr);
                else
                    nodes.push_back(new TreeNode(std::stoi(tmp)));
                prev = ++i;
            }
        }

        return nodes;
    }
};
