#include <iostream>

#include "solution.cc"

void test() {
    Solution solution;
    string result = solution.predictPartyVictory("RRDRDDD");
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
