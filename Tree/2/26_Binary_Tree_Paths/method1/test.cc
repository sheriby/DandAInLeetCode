#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{3, 1, 4, -1, 2};
    TreeNode* tree = vectorToTree(v);
    auto res = s.binaryTreePaths(tree);
    for (auto&& val : res) {
        std::cout << "val: " << val << std::endl;
    }
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
