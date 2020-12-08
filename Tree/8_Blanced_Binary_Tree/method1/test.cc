#include <vector>

#include "solution.cc"
#include "treeutils.cc"
using std::vector;

void test() {
    Solution solution;
    // vector<int> v{3, 9, 20, -1, -1, 15, 7};
    vector<int> v{1, 2, 2, 3, 3, -1, -1, 4, 4};
    TreeNode* tree = vectorToTree(v);
    bool res = solution.isBalanced(tree);
    std::cout << res << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
