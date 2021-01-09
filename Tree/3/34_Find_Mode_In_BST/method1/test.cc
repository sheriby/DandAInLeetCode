#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{2, 1, 3, 1, -1, 3};
    TreeNode* tree = vectorToTree(v);
    vector<int> result = s.findMode(tree);
    for (auto&& val : result) {
        std::cout << "val: " << val << std::endl;
    }
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
