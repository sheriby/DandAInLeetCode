#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{1, 2, 3, -1, 5, -1, 4};
    TreeNode* tree = vectorToTree(v);
    vector<int> result = s.rightSideView(tree);
    printVector(result);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
