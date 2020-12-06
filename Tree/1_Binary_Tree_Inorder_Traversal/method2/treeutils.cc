#include <iostream>
#include <queue>
#include <vector>
#include "treenode.h"

using std::cout;
using std::endl;
using std::queue;
using std::vector;

/**
 *  val == -1 => null 
 */
TreeNode* makeTreenode(int val) {
    if (val == -1) {
        return nullptr;
    }
    return new TreeNode(val);
}

TreeNode* arrayToTree(int arr[], int len) {
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

template <typename T>
void printVector(vector<T> v) {
    cout << "[ ";
    for (auto val : v) {
        cout << val << " ";
    }
    cout << "]" << endl;
}