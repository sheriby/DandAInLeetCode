#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{4, 5, 2, 4, 3, 3, 1, 2, 5, 4};
    int result = s.maxProfit(v, 1);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
