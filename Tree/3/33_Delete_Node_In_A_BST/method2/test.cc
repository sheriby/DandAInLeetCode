#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{5, 3, 6, 2, 4, -1, 7};
    TreeNode* tree = vectorToTree(v);
    tree = s.deleteNode(tree, 3);
    printTree(tree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
