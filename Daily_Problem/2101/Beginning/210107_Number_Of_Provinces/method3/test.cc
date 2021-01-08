#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<vector<int>> m{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int result = s.findCircleNum(m);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}