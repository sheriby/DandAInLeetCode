#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Codec s;
    // TreeNode* tree = vectorToTree(v);
    TreeNode* tree = s.deserialize("[3,1,4,null,2]");
    string res = s.serialize(tree);
    std::cout << "res: " << res << std::endl;
    // printTree(tree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
