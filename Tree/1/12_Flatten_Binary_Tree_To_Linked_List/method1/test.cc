#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution solution;
    // vector<int> v{1, 2, 5, 3, 4, -1, 6};
    vector<int> v;
    TreeNode* tree = vectorToTree(v);
    solution.flatten(tree);
    printTree(tree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
