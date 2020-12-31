#include <iostream>
#include <vector>

#include "treenode.h"

using std::vector;

static const auto __ = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    // 显示地进行二叉树的中序遍历
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        std::pair<int, int> res = findTwoSwapped(nums);
        recover(root, res.first, res.second, 2);
    }

   private:
    // 二叉搜索树的中序遍历应该是一个有序的数组
    // 这里采用的是最简单的递归法中序遍历
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root) {
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }
    }

    // 通过遍历中序遍历得到的数组，从而得到需j交换顺序的两个数
    std::pair<int, int> findTwoSwapped(vector<int>& nums) {
        std::pair<int, int> result;
        bool flag = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (flag) {
                    result.first = nums[i];
                    result.second = nums[i + 1];
                    flag = false;
                } else {
                    result.second = nums[i + 1];
                    break;
                }
            }
        }

        return result;
    }

    // 交换两个指定的数的节点中的数据
    void recover(TreeNode* root, int x, int y, int count) {
        if (!root || !count) return;
        if (root->val == x || root->val == y) {
            root->val = root->val == x ? y : x;
            count--;
        }
        recover(root->left, x, y, count);
        recover(root->right, x, y, count);
    }
};