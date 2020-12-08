#include <vector>

#include "solution.cc"
#include "treeutils.cc"
using std::vector;

void test() {
    Solution solution;
    // vector<int> v{3, 9, 20, -1, -1, 15, 7};
    vector<int> v{2, -1, 3, -1, 4, -1, 5, -1, 6};
    TreeNode* tree = vectorToTree(v);
    int res = solution.minDepth(tree);
    std::cout << res << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
