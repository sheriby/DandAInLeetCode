#include <vector>

#include "solution.cc"
#include "treeutils.cc"
using std::vector;

void test() {
    Solution solution;
    vector<int> v{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    TreeNode* tree = vectorToTree(v);
    int sum = 22;
    int res = solution.hasPathSum(tree, sum);
    std::cout << res << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
