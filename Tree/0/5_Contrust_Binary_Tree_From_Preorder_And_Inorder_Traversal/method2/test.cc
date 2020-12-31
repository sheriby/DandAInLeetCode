#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution solution;
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode* tree = solution.buildTree(preorder, inorder);
    printTree(tree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
