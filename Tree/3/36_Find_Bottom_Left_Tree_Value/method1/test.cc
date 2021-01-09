#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, -1, -1, -1, 7};
    TreeNode* tree = vectorToTree(v);
    int result = s.findBottomLeftValue(tree);
    std::cout << "result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
