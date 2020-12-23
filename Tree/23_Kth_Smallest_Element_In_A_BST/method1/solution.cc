#include <iostream>
#include <vector>

#include "treenode.h"

using std::vector;

class Solution {
   public:
    // 二叉树的中序遍历就是有序的
    // 不过递归的方法有个缺点，我们不能提前终止递归，也就是说我们要
    // 遍历完一整颗树
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, k, nums);
        return nums[k - 1];
    }

   private:
    void inorder(TreeNode* root, int k, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, k, nums);
        nums.push_back(root->val);
        inorder(root->right, k, nums);
    }
};