#include <deque>
#include <iostream>
#include <vector>

#include "treenode.h"
using std::deque;
using std::vector;

class Solution {
   public:
    // 除了可以使用BFS之外，还可以使用DFS来做
    // 此时每行的容器不得不使用deque了，因为C++中没有双端操作的数组，这种方法还更浪费内存空间
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>{};
        vector<deque<int>> result;
        DFS(root, 0, result);
        vector<vector<int>> ret;
        for (auto& val : result) {
            ret.push_back(dequeToVector(val));
        }

        return ret;
    }

   private:
    void DFS(TreeNode* root, int level, vector<deque<int>>& result) {
        if (level >= result.size()) {
            deque<int> newLevel;
            newLevel.push_back(root->val);
            result.push_back(newLevel);
        } else if (level & 1) {
            result[level].push_back(root->val);
        } else {
            result[level].push_front(root->val);
        }
        if (root->left) DFS(root->left, level + 1, result);
        if (root->right) DFS(root->right, level + 1, result);
    }

    vector<int> dequeToVector(deque<int>& deque) {
        vector<int> res;
        while (!deque.empty()) {
            res.emplace_back(deque.back());
            deque.pop_back();
        }
        return res;
    }
};