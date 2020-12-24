#include <iostream>

#include "solution.cc"

void test() {
    Solution s;
    vector<int> v{1, 0, 2};
    int result = s.candy(v);
    std::cout << "Result: " << result << std::endl;
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
