#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};
    TreeNode* tree = vectorToTree(v);
    int result = s.pathSum(tree, 8);
    std::cout << "result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
