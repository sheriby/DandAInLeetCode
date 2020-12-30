#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{1, 3};
    int result = s.minPatches(v, 6);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
