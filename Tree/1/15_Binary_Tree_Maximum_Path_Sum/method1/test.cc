#include <vector>

#include "solution.cc"
#include "treeutils.cc"
using std::vector;

void test() {
    vector<int> v{-10, 9, 20, -1, -1, 15, 7};
    TreeNode* tree = vectorToTree(v);
    Solution s;
    int result = s.maxPathSum(tree);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
