#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    char res = s.findTheDifference("abcd", "badce");
    std::cout << "Result: " << res << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
