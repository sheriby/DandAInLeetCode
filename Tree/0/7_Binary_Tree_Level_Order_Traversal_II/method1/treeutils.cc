#include <iostream>
#include <queue>
#include <vector>

#include "treenode.h"

using std::cout;
using std::endl;
using std::queue;
using std::vector;

TreeNode* makeTreenode(int val) {
    if (val == -1) {
        return nullptr;
    }
    return new TreeNode(val);
}

/*
    val = -1 means null
*/
TreeNode* vectorToTree(vector<int> arr) {
    int len = arr.size();
    if (!len) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    TreeNode *current, *left, *right;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int index = 1;
    while (true) {
        current = nodeQueue.front();
        nodeQueue.pop();

        if (index >= len) break;
        left = makeTreenode(arr[index++]);
        if (left) {
            current->left = left;
            nodeQueue.push(left);
        }

        if (index >= len) break;
        right = makeTreenode(arr[index++]);
        if (right) {
            current->right = right;
            nodeQueue.push(right);
        }
    }

    return root;
}

vector<int> treeToVector(TreeNode* node) {
    if (!node) return vector<int>(0);
    queue<TreeNode*> nodeQueue;
    vector<int> result;
    nodeQueue.push(node);

    while (!nodeQueue.empty()) {
        node = nodeQueue.front();
        nodeQueue.pop();
        if (node) {
            result.push_back(node->val);
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        } else {
            result.push_back(-1);
        }
    }

    while (result.back() == -1) {
        result.pop_back();
    }

    return result;
}

template <typename T>
void printVector(vector<T> v) {
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }

    cout << v.back() << "]" << endl;
}

void printTree(TreeNode* tree) { printVector(treeToVector(tree)); }