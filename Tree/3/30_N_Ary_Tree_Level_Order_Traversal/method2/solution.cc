#include <queue>
#include <vector>

#include "node.h"
using std::queue;
using std::vector;

class Solution {
   public:
    // 基于递归的层序遍历
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root) levelOrder(root, 0, result);
        return result;
    }

   private:
    void levelOrder(Node* root, int level, vector<vector<int>>& lists) {
        if (lists.size() == level) lists.push_back(vector<int>{});
        lists[level].push_back(root->val);
        for (auto&& c : root->children) {
            levelOrder(c, level + 1, lists);
        }
    }
};