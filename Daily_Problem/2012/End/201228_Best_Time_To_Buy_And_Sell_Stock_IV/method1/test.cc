#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{2, 4, 1};
    int result = s.maxProfit(2, v);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
