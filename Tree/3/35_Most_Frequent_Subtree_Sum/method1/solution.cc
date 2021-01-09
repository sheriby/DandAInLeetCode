#include <algorithm>
#include <unordered_map>
#include <vector>

#include "treenode.h"
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> results;
        if (!root) return results;

        unordered_map<int, int> map;
        subtreeSum(root, map);
        // 找到最大的value所对应的key有哪些
        // 两次循环，先找到最大的value，然后根据value找key
        int max_count = 0;
        for (auto&& m : map) {
            max_count = std::max(m.second, max_count);
        }

        for (auto&& m : map) {
            if (m.second == max_count) results.push_back(m.first);
        }

        return results;
    }

   private:
    int subtreeSum(TreeNode* root, unordered_map<int, int>& map) {
        if (!root) return 0;
        int left = subtreeSum(root->left, map);
        int right = subtreeSum(root->right, map);

        int ret = left + right + root->val;
        map[ret]++;
        return ret;
    }
};