#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Codec s;
    // vector<int> v{3, 1, 4, -1, 2};
    vector<int> v{3, 2, 4, 3};
    TreeNode* tree = vectorToTree(v);
    std::cout << "tree->right->val: " << tree->right->val << std::endl;
    printTree(tree);
    string res = s.serialize(tree);
    std::cout << "res: " << res << std::endl;
    TreeNode* rtree = s.deserialize(res);
    printTree(rtree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
