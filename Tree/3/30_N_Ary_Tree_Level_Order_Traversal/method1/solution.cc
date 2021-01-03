#include <queue>
#include <vector>

#include "node.h"
using std::queue;
using std::vector;

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            vector<int> level;
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++) {
                root = nodeQueue.front();
                nodeQueue.pop();

                level.push_back(root->val);
                for (auto&& c : root->children) {
                    nodeQueue.push(c);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};