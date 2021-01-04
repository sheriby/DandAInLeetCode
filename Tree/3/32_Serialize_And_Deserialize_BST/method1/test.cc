#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Codec s;
    vector<int> v{8, 6, 9, 4, 7};
    TreeNode* tree = vectorToTree(v);
    string result = s.serialize(tree);
    std::cout << "result: " << result << std::endl;
    // TreeNode* t = s.deserialize(result);
    // printTree(t);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
