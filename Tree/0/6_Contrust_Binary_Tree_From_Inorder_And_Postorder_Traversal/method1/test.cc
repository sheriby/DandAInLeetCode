#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution solution;
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};
    TreeNode* tree = solution.buildTree(inorder, postorder);
    printTree(tree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
