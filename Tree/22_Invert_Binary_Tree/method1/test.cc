#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6};
    TreeNode* tree = vectorToTree(v);
    TreeNode* result = s.invertTree(tree);
    printTree(result);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
