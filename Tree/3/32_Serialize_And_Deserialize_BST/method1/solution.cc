#include <iostream>
#include <string>
#include <vector>

#include "treenode.h"

using std::string;
using std::vector;

class Codec {
   public:
    // 之前是序列化一棵一般的树这次是序列化二叉搜索树
    // 我感觉最简单的方法可能就是先序遍历了
    // BST的根节点确定了，其形状也就确定了

    string serialize(TreeNode* root) {
        string res = "";
        preorder(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        vector<int> nums = split(data);
        return buildTree(nums, 0, nums.size());
    }

   private:
    void preorder(TreeNode* root, string& res) {
        if (!root) return;
        res += std::to_string(root->val) + ",";
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> split(const string& data) {
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

    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;

        TreeNode* newnode = new TreeNode(nums[left]);
        int mid = right;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[left]) {
                mid = i;
                break;
            }
        }

        newnode->left = buildTree(nums, left + 1, mid);
        newnode->right = buildTree(nums, mid, right);

        return newnode;
    }
};