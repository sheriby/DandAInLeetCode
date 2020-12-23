#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{3, 1, 4, -1, 2};
    TreeNode* tree = vectorToTree(v);
    int result = s.kthSmallest(tree, 2);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
