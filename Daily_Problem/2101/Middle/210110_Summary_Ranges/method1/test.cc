#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{-1, 0, 1, 2, 3, 5, 6, 8};
    vector<string> result = s.summaryRanges(v);
    for (auto&& val : result) {
        std::cout << "val: " << val << std::endl;
    }
}

int main() {
    test();
    return 0;
}