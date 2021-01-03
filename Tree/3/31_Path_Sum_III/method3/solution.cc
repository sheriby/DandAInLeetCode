#include <unordered_map>

#include "treenode.h"
using std::unordered_map;

class Solution {
   public:
    // 记忆化搜索，利用前缀和
    // 前缀和指的是一个节点到根节点的路径中的结点元素总和
    // 如果两个结点的前缀和相差为sum，那么则两个结点之间的路径的和就是sum
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        unordered_map<int, int> map;
        map[0] = 1;
        return pathSumDFS(root, 0, sum, map);
    }

   private:
    int pathSumDFS(TreeNode* root, int prefix, int sum,
                   unordered_map<int, int>& map) {
        if (!root) return 0;

        int result = 0;
        prefix += root->val;
        if (map.count(prefix - sum)) {
            result += map[prefix - sum];
        }

        ++map[prefix];

        result += pathSumDFS(root->left, prefix, sum, map);
        result += pathSumDFS(root->right, prefix, sum, map);

        --map[prefix];

        return result;
    }
};