#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{4, 9, 0, 5, 1};
    TreeNode* tree = vectorToTree(v);
    vector<int> result = s.preorderTraversal(tree);
    printVector(result);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
