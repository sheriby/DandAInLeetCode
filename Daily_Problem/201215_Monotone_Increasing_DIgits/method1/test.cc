#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    int result = s.monotoneIncreasingDigits(321);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
