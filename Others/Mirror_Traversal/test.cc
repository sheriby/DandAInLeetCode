#include <iostream>

#include "mirror_traversal.hpp"
#include "treeutils.cc"

void test() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    TreeNode* tree = vectorToTree(v);
    vector<int> results = MirrorTraversal::mirrorTraversal(tree);
    for (auto&& val : results) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}