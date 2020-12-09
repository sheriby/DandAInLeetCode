#include <vector>

#include "solution.cc"
#include "treeutils.cc"
using std::vector;

void test() {
    Solution solution;
    vector<int> v{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    TreeNode* tree = vectorToTree(v);
    int sum = 22;
    auto res = solution.pathSum(tree, sum);
    for (auto a : res) {
        for (auto val : a) {
            std::cout << val << ",";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
