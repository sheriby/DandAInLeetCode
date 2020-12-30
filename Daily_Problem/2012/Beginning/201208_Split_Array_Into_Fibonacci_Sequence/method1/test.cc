#include <iostream>

#include "solution.cc"

void test() {
    Solution solution;
    string str = "123456579";
    auto res = solution.splitIntoFibonacci(str);
    for (auto val : res) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
