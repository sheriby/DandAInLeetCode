#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
    auto result = s.maxSlidingWindow(v, 1);
    for (auto&& r : result) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
}

int main() {
    test();
    return 0;
}