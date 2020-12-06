#include <iostream>

#include "solution.cc"

void test() {
    Solution solution;
    int res = solution.numTrees(3);
    std::cout << "Result: " << res << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
