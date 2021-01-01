#include <string>
#include <vector>

#include "treenode.h"

using std::string;
using std::vector;

class Solution {
   public:
    // 典型的dfs
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;

        binaryTreePaths(root, "", result);
        return result;
    }

   private:
    void binaryTreePaths(TreeNode* root, string path, vector<string>& paths) {
        string rootval = std::to_string(root->val);
        string newpath;
        if (path.empty())
            newpath = rootval;
        else
            newpath = path + "->" + rootval;

        if (root->left) {
            binaryTreePaths(root->left, newpath, paths);
        }
        if (root->right) {
            binaryTreePaths(root->right, newpath, paths);
        }
        if (!root->left && !root->right) {
            paths.push_back(newpath);
        }
    }
};