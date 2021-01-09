#include <vector>

#include "treenode.h"
using std::vector;

class Solution {
   public:
    // 中序遍历得到有序数组，然后找众数就完事了
    // 可以通过一次遍历找，也可以通过map找
    // 如果通过map找的话，甚至可以不需要中序遍历
    vector<int> findMode(TreeNode* root) {
        vector<int> results;
        if (!root) return results;

        vector<int> list;
        inorder(root, list);
        int maxcounter = 1;
        int counter = 1;
        results.push_back(list[0]);
        for (int i = 1; i < list.size(); i++) {
            if (list[i] == list[i - 1]) {
                ++counter;
            } else
                counter = 1;
            if (counter > maxcounter) {
                maxcounter = counter;
                results.clear();
                results.push_back(list[i]);
            } else if (counter == maxcounter) {
                results.push_back(list[i]);
            }
        }

        return results;
    }

   private:
    void inorder(TreeNode* root, vector<int>& list) {
        if (!root) return;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
};