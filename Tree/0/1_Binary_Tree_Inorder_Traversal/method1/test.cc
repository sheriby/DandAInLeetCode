#include "solution.cc"
#include "treeutils.cc"

void test() {
    int arr[] = {1, -1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    TreeNode* tree = arrayToTree(arr, len);
    Solution solution;
    vector<int> result = solution.inorderTraversal(tree);
    printVector(result);
}

int main(int argc, char const* argv[]) {
    test();
    return 0;
}
