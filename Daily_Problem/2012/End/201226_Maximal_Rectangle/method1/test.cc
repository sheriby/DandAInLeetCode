#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<vector<char>> m{{'1', '1', '1', '1'},
                           {'1', '1', '1', '1'},
                           {'1', '1', '1', '0'},
                           {'1', '0', '0', '1'}};
    int result = s.maximalRectangle(m);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
