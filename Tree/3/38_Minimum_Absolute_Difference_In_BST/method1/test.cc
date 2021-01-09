#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{5, 3, 6, 2, 4, -1, 7};
    TreeNode* tree = vectorToTree(v);
    int result = s.getMinimumDifference(tree);
    std::cout << "result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
