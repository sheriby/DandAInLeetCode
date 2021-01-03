#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{3, 9, 20, -1, -1, 15, 7};
    TreeNode* tree = vectorToTree(v);
    int result = s.sumOfLeftLeaves(tree);
    std::cout << "result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
