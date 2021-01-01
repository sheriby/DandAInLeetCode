#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "treenode.h"
using std::queue;
using std::string;
using std::vector;

// 阿这，我一开始在treeutils里面就写了vector和tree互转的函数
// 现在看来和这个题目的思路应该是差不多的
class Codec {
   public:
    string serialize(TreeNode* root) {
        if (!root) return "[]";

        vector<string> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            root = nodeQueue.front();
            nodeQueue.pop();

            if (root) {
                result.push_back(std::to_string(root->val));
                nodeQueue.push(root->left);
                nodeQueue.push(root->right);
            } else {
                result.push_back("null");
            }
        }

        while (result.back() == "null") {
            result.pop_back();
        }

        string resultstr = "[";
        for (auto&& e : result) {
            resultstr += e + ",";
        }
        resultstr[resultstr.size() - 1] = ']';

        return resultstr;
    }

    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;

        vector<TreeNode*> nodes = str2TreeArray(data);
        TreeNode* root = nodes[0];
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        int index = 1;
        int len = nodes.size();
        while (index < len) {
            TreeNode* current = nodeQueue.front();
            nodeQueue.pop();

            TreeNode* left = nodes[index++];
            if (left) {
                current->left = left;
                nodeQueue.push(left);
            }

            if (index >= len) break;

            TreeNode* right = nodes[index++];
            if (right) {
                current->right = right;
                nodeQueue.push(right);
            }
        }

        return root;
    }

   private:
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
