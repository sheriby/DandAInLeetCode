#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{3, 3, 5, 0, 0, 3, 1, 4};
    int result = s.maxProfit(v);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}