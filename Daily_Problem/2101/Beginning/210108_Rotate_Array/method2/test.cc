#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    s.rotate(v, 3);
    for (auto&& val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}