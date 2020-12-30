#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    bool result = s.wordPattern("abba", "dog cat cat dog");
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
