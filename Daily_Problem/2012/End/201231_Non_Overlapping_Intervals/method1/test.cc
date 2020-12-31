#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<vector<int>> vv{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = s.eraseOverlapIntervals(vv);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}