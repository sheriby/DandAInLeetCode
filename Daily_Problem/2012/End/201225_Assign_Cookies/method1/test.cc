#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v1{1, 2, 3};
    vector<int> v2{1, 4};
    int result = s.findContentChildren(v1, v2);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
