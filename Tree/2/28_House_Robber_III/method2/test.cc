#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{3, 2, 3, -1, 3, -1, 1};
    TreeNode* tree = vectorToTree(v);
    int result = s.rob(tree);
    std::cout << "result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
