#include "solution.cc"
#include "treeutils.cc"

void test() {
    Solution solution;
    vector<int> v{3, 9, 20, 1, 2, 15, 7, 3, 8, -1, 6};
    TreeNode* tree = vectorToTree(v);
    auto res = solution.zigzagLevelOrder(tree);
    for (auto v : res) {
        for (auto val : v) {
            std::cout << val << " ";
        }
        std::cout << endl;
    }
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
