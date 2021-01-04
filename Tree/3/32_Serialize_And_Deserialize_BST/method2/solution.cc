#include <iostream>
#include <string>
#include <vector>

#include "treenode.h"

using std::string;
using std::vector;

class Codec {
   public:
    // 在不考虑序列化的数据的可读性的前提下，我们可以直接序列化
    // 数的int值（也就是四个字节）
    // 同时我们还可以不用使用分隔符

    // 不过只知道为啥leetcode最后两个按钮总是过不去？？？为啥
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
        res += int2str(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> split(const string& data) {
        int n = data.size() / 4;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            string strval = data.substr(i * 4, 4);
            result.push_back(str2int(strval));
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

    string int2str(unsigned int a) {
        string res = "";
        for (int i = 0; i < 4; i++) {
            res += a & 0xff;
            a >>= 8;
        }

        return res;
    }

    int str2int(const string& str) {
        unsigned int res = 0;
        for (int i = 3; i >= 0; i--) {
            res |= (unsigned int)str[i];
            if (i) res <<= 8;
        }

        return res;
    }
};