#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution s;
    vector<int> v{5, 2, -5};
    TreeNode* tree = vectorToTree(v);
    vector<int> result = s.findFrequentTreeSum(tree);
    for (auto&& val : result) {
        std::cout << "val: " << val << std::endl;
    }
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
