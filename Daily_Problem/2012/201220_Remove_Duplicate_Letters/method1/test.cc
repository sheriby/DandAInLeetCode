#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    string result = s.removeDuplicateLetters("fdaffqedfhaslqwiqhda");
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
