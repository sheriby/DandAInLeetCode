#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{3, 1, 4, -1, 2};
    TreeNode* tree = vectorToTree(v);
    TreeNode* result =
        s.lowestCommonAncestor(tree, tree->left->right, tree->right);
    std::cout << "Result: " << result->val << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
