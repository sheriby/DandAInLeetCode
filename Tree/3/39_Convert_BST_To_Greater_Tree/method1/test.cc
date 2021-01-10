#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{3, 2, 4, 1};
    TreeNode* tree = vectorToTree(v);
    TreeNode* result = s.convertBST(tree);
    printTree(result);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
