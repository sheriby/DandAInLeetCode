#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode* tree = vectorToTree(v);
    int result = s.countNodes(tree);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
