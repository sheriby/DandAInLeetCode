#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution solution;
    vector<int> v{3, 9, 20, -1, -1, 15, 7};
    TreeNode* tree = vectorToTree(v);
    auto res = solution.levelOrderBottom(tree);
    for (auto&& v : res) {
        printVector(v);
    }
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
