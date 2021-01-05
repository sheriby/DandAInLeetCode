#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    auto res = s.largeGroupPositions("abbbxxxxzyy");
    for (auto&& v : res) {
        for (auto&& val : v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    test();
    return 0;
}