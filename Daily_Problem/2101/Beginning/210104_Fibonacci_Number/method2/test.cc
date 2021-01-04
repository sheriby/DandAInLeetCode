#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    int result = s.fib(20);
    std::cout << "result: " << result << std::endl;
}

int main() {
    test();
    return 0;
}