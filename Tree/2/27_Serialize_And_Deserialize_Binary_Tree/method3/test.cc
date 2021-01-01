#include <iostream>

#include "solution.cc"
#include "treeutils.cc"

void test() {
    Codec s;
    vector<int> v{3, 1, 4, -1, 2};
    TreeNode* tree = vectorToTree(v);
    // TreeNode* tree = s.deserialize("[3,1,null,2,null,null,4,null,null]");
    string res = s.serialize(tree);
    std::cout << "res: " << res << std::endl;
    TreeNode* rtree = s.deserialize(res);
    printTree(rtree);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
