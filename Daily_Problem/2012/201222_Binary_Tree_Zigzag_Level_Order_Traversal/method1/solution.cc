#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "treenode.h"
using std::queue;
using std::stack;
using std::vector;

class Solution {
   public:
    // 总体还是比较简单的，因为每次遍历一层之后需要翻转顺序，所以需要使用栈结构
    // 其实是使用了一个栈以及一个队列的BFS
    // C++中的vector不可以像java当中LinkedList那样可以在两端插入删除
    // 因而使用一个栈来翻转 (这里使用deque也是不怎么样的，还不如stack)
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>{};

        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;
        stack<TreeNode*> tempStack;
        TreeNode* node = nullptr;
        // 当前的遍历的顺序是否是从左到右的
        bool left2right = true;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            vector<int> level;
            // 遍历一层
            while (!nodeQueue.empty()) {
                node = nodeQueue.front();
                nodeQueue.pop();
                level.push_back(node->val);
                if (left2right) {
                    if (node->left) tempStack.push(node->left);
                    if (node->right) tempStack.push(node->right);
                } else {
                    if (node->right) tempStack.push(node->right);
                    if (node->left) tempStack.push(node->left);
                }
            }
            result.push_back(level);
            // 下一层的方向相反
            left2right = !left2right;

            // 使用栈先进后出将下一层的元素放入队列中
            while (!tempStack.empty()) {
                nodeQueue.push(tempStack.top());
                tempStack.pop();
            }
        }

        return result;
    }
};