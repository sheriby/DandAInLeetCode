#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int result = s.minCostClimbingStairs(v);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
