#include "treeutils.cc"
#include "solution.cc"

void test() {
    vector<int> v{1, 3, -1, -1, 2};
    TreeNode* tree = vectorToTree(v);

    Solution solution;
    solution.recoverTree(tree);

    vector<int> result = treeToVector(tree);
    printVector(result);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
