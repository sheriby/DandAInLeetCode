#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{1, 0, 0, 0, 0, 0, 1};
    bool result = s.canPlaceFlowers(v, 3);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}