#include <iostream>

#include "solution.cc"

void test() {
    Solution solution;
    vector<int> v{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int result = solution.wiggleMaxLength(v);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
